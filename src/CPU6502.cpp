#include "CPU6502.h"
#include "Bus.h"

CPU6502::CPU6502()
{
}

CPU6502::~CPU6502()
{
}

void CPU6502::write(uint16_t addr, uint8_t data)
{
    return bus->write(addr, data);
}

uint8_t CPU6502::read(uint16_t addr)
{
    return bus->read(addr, false);
}