#ifndef DATA_HPP
#define DATA_HPP

class Data {
    public:
        Data();
        ~Data();
        Data(const Data& other);
        Data& operator=(const Data& other);
        int x;
};

#endif
