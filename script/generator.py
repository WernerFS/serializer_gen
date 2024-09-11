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

## solve mixed states, number of states cannot!!! exceed number of words in pkt
## in a loop add words till 4, then name state according to original signals, should tie all validates 
## make a list (field_name, w_size)

def generate_interface(specs: dict, msg_name: str):
    name_size = []
    fields = ''
    data = []
    states = ['idle', 'rst']
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
            min_latency += s_wordsz
            tsize += s_bytes
            name_size.extend([name] * s_words)
        valid_states = ',\n\t\t'.join(states)
        data_fields = '\n\t\t'.join(data)
        outf.write(interface.states.format(valid_states = valid_states))
        outf.write(interface.union.format(tsize = tsize, data_fields = data_fields))
        outf.write(interface.type_struct.format(fields = fields))
        return name_size, tsize, states[2:], min_latency
    
# consume (field_name, w_size) for avails in each state
def generate_encoder(name_size, tsize, states, min_latency, msg_name):
    fsm = encoder(tsize, states)
    avail_fields = []
    avail_fields_reset = []
    avail_fields_update = []
    with open(name + '.sv', 'w', encoding = 'utf-8') as outf:
        outf.write(fsm.header)
        for name, _ in name_size:
            avail_fields.append(fsm.field_avail.format(field = name))
            avail_fields_reset.append(fsm.avail_reset.format(field = name))
            avail_fields_update.append(fsm.update_fields.format(field = name))
        outf.write(fsm.internals.format(avail_fields))
        outf.write(fsm.initials.format(msg_name))
        outf.write(fsm.fsm_start)
        outf.write(fsm.update_avails.format(avail_fields_reset = avail_fields_reset, update_fields = avail_fields_update))

        # get states
        outf.write(fsm.pkt_start_s.format(pkt_ready = min_latency, first_field = states[0]))
        outf.write(fsm.first_field_s.format(first_field = states.pop(0), next_field = states[0].split("_")[0], field_bytes = , next_state = states[0]))
        last_state = fsm.last_field_word_s.format(pkt_ready = min_latency, first_field = states.pop())
        for i, s in enumerate(states):
            # add states
            pass


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

