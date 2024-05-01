# Serializer generator

The purpose of this project is to provide all necessary tools for generating and validating protocol agnostic generators.
As input, the Python generator requires the package type, fields, data widths and eventual available cycle in an yaml format.

Example:

```yaml
my_pkt:
  msg_type: 1
  fields:
    - first_fld  : {"dwidth": 6, "avail_cycle": 0 }
    - second_fld  : {"dwidth": 6, "avail_cycle": 0 }
```

The generator will parse and create an RTL serializer with data and ready ports for each field and the field type.
The internal logic of the serializer consists of a FSM that goes through each of the ports or cached fields feeding them to a streaming bus.
The output bus has data, ready, valid, and lenght ports.
The lenght port is used to indicated the valid bytes in the last word.
Additionally, the serializer will try to minimize the latency by scheduling all transactions as soon as possible.

