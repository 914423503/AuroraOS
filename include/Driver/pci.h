/*
AuroraKernel SourceCode
Programmer: LeonardoBaldazzi
Contents: PCI Header
*/
#ifndef _PCI_H_
#define _PCI_H_

//Define

//Include
#include "../variables.h"

uint16 pci_read_word(uint16 bus, uint16 slot, uint16 func, uint16 offset) //Read a word from pci
{
	uint64 address;
    uint64 lbus = (uint64)bus;
    uint64 lslot = (uint64)slot;
    uint64 lfunc = (uint64)func;
    uint16 tmp = 0;
    address = (uint64)((lbus << 16) | (lslot << 11) |
              (lfunc << 8) | (offset & 0xfc) | ((uint32)0x80000000));
    outportb (0xCF8, address);
    tmp = (uint16)((inportb (0xCFC) >> ((offset & 2) * 8)) & 0xffff);
    return (tmp);
}

uint16 getVendorID(uint16 bus, uint16 device, uint16 function) //Return Vendor ID
{
        uint32 r0 = pci_read_word(bus, device, function, 0);
        return r0;
}

uint16 getDeviceID(uint16 bus, uint16 device, uint16 function) //Return Device ID
{
        uint32 r0 = pci_read_word(bus, device, function, 2);
        return r0;
}

uint16 getClassId(uint16 bus, uint16 device, uint16 function) //Return Class ID
{
        uint32 r0 = pci_read_word(bus, device, function, 0xA);
        return (r0 & ~0x00FF) >> 8;
}

uint16 getSubClassId(uint16 bus, uint16 device, uint16 function) //Return SubClkass ID
{
        uint32 r0 = pci_read_word(bus, device, function, 0xA);
        return (r0 & ~0xFF00);
}

#endif
