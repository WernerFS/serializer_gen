#!/usr/bin/env python3
"""
All rights reserved (C) 2024. Werner Florian

Python tool to generate SystemVerilog packet encoder from YAML packet specification.
From the specification the encoder with the appropriate field-specific interfaces is 
generated. At the same time, it is possible to generate the SBY file for formal 
verification with the Yosys framework and a COCOTB testbench.
"""

__version__ = "1.0"

from templates import interface, encoder
from functools import partial
import yaml, argparse, sys
from pathlib import Path
from math import ceil
    
def choose_msg_type(specs: dict):
    msg_types = list(specs.keys())
    print(f"Number of packets defined in file: {len(specs)}")
    print('\tOption\tmessage type:')
    for i, msg_type in enumerate(specs):
        print(f'\t{i}\t{msg_type}')
    selection = int(input('Choose a single message type from the list:'))
    return specs[msg_types[selection]], msg_types[selection] \
        if (selection < len(specs) and selection >= 0) else choose_msg_type(specs)

def generate_interface(specs: dict, msg_name: str):
    fields = ''
    data = []
    states = ['idle']
    tsize = 0
    min_latency = 1
    with open(msg_name + '.sv', 'w', encoding = 'utf-8') as outf:
        outf.write(interface.header)
        msg_types = interface.msg_type.format(name = msg_name, index = specs['msg_type'])
        outf.write(interface.types_enum.format(types = msg_types))
        for field_specs in specs['fields']:
            name = list(field_specs.keys())[0]
            s_words = ceil(field_specs[name]['size'] / 4)
            s_bytes = field_specs[name]['size']
            fields += interface.fields.format(name = name, size = s_bytes - 1)
            data.append(interface.data_field.format(name = name, size = s_bytes - 1))
            for i in range(s_words):
                states.append(interface.state.format(name = name, n = i))
            if field_specs[name]['avail_cycle'] > min_latency:
                min_latency += 1
            min_latency += s_words
            tsize += s_bytes
        valid_states = ',\n\t\t'.join(states)
        data_fields = '\n\t\t'.join(data)
        outf.write(interface.states.format(valid_states = valid_states))
        outf.write(interface.union.format(tsize = tsize, data_fields = data_fields))
        outf.write(interface.type_struct.format(fields = fields))
        return specs['fields'], tsize, states, min_latency

def generate_encoder(specs, name, tsize, states, min_latency, msg_name):
    avail_fields = []
    avail_fields_reset = []
    avail_fields_update = []
    field_states = []
    with open(name + '.sv', 'w', encoding = 'utf-8') as outf:
        outf.write(encoder.header)
        for i, field_specs in enumerate(specs['fields']):
            name = list(field_specs.keys())[0]
            s_words = ceil(field_specs[name]['size'] / 4)
            avail_fields.append(encoder.field_avail.format(field = name))
            avail_fields_reset.append(encoder.avail_reset.format(field = name))
            avail_fields_update.append(encoder.update_fields.format(field = name))
        for i, s in enumerate(states):
            if i == 0:
                first_state = encoder.pkt_start_s.format(pkt_ready = min_latency, first_field = name)
            else:
                
        outf.write(encoder.internals.format(avail_fields))
        outf.write(encoder.initials.format(msg_name))
        outf.write(encoder.fsm_start)
        outf.write(encoder.update_avails.format(avail_fields_reset = avail_fields_reset, update_fields = avail_fields_update))



def main():
    """Entry point for the application
    Parameters
    ----------
    Message spec file (.yaml)
    Returns
    -------
    src/st_encoder_msg_type.sv
    src/st_encoder_msg_type.sby
    """
    parser = argparse.ArgumentParser(description = __doc__)
    parser.add_argument('filename', type = str, 
        help = 'Path to the yaml file containing the message specs to generate the encoder.')
    parser.add_argument('-o', '--output', default = 'st_encoder.sv', type = str, 
        help = 'Output path for the generated encoder.')
    parser.add_argument('-t', default = 'st_encoder_tb.??', type = str,
        help ='Generate COCOTB testbench')
    args = parser.parse_args()
    file_path = Path(args.filename)

    if not file_path.is_file():
        print(f"File Error: {args.filename} does not exists.")
        sys.exit()
    if file_path.suffix != '.yaml':
        print(f"File type error: {args.filename} of wrong type. Only YAML files supported.")
        sys.exit()
    
    try:
        msg_specs = yaml.safe_load(file_path.read_text())
    except yaml.YAMLError as exc:
        sys.exit(exc)
    except IOError as exc:
        sys.exit(exc)
  
    if len(msg_specs) > 1:
        specs, msg_name = choose_msg_type(msg_specs)
    specs, tsize, states, min_latency = generate_interface(specs, msg_name)
    generate_encoder(specs, args.ouput, tsize, states, min_latency, msg_name)

if __name__ == '__main__':
    sys.exit(main())

