#ifndef RUNNER_HPP
#define RUNNER_HPP

#include "parser.hpp"

#include <fstream>
#include <vector>
namespace Roee_ELF {

    struct loaded_segment {
        uint64_t v_addr;
        uint64_t size_in_mem;
        uint64_t* buff;
    };
    class Runner final {
    public:
        Runner(Parser_64b* const parser);
        void run(void);

    private:
        void map_segments(void);
        uint64_t* alloc_seg_buff(const uint16_t i) const;

    private:
        Parser_64b* parser;

        std::vector<loaded_segment> loaded_segments;
        uint16_t code_segment_i;
    };
}

#endif