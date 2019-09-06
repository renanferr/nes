#include <cstdint>

class Bus;

class CPU6502
{
    public:
        CPU6502();
        ~CPU6502();

        void ConnectBus(Bus *b)
        {
            bus = b;
        }

        enum FLAGS6502
        {
            C = (1 << 0), // carry bit
            Z = (1 << 1), // zero
            I = (1 << 2), // disable interrupts
            D = (1 << 3), // decimal mode
            B = (1 << 4), // break
            U = (1 << 5), // unused
            V = (1 << 6), // overflow
            N = (1 << 7), // negative
        };

        uint8_t     a = 0x00;       // accumulator register
        uint8_t     x = 0x00;       // x register
        uint8_t     y = 0x00;       // y register
        uint8_t     stkp = 0x00;    // stack pointer
        uint16_t    pc = 0x00;     // program counter
        uint8_t     status = 0x00;  // status register


    private:
        Bus     *bus = nullptr;
        uint8_t read(uint16_t addr);
        void    write(uint16_t addr, uint8_t data);

        uint8_t GetFlag(FLAGS6502 f);
        void    SetFlag(FLAGS6502 f, bool val);
};