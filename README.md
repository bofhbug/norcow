# NORCOW

[![Build Status](https://travis-ci.org/trezor/norcow.svg?branch=master)](https://travis-ci.org/trezor/norcow) [![gitter](https://badges.gitter.im/trezor/community.svg)](https://gitter.im/trezor/community)

Copy-on-Write (COW) Key-Value Storage for NOR Flash devices

See `norcow.h` for the API.

## Record format

| offset | length | type     | field        |
|-------:|-------:|----------|--------------|
| 0x0000 | 2      | uint16_t | key          |
| 0x0002 | 2      | uint16_t | value length |
| 0x0004 | length | bytes    | value        |
