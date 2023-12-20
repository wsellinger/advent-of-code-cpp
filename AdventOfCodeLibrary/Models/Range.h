#pragma once

struct Range 
{
public:
    size_t Start = 0;
    size_t End = 0;

    size_t Count() const { return End > Start ? End - Start : 0; }
};