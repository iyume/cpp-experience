#include <iostream>

// Wrapper to read bytes
class Reader {
  public:
    // NOTE: istream must be opened in binary mode, or it will get wrong size on
    // windows platform on CRLF
    explicit Reader(std::istream& is)
        : _is(is){
              // file.seekg(std::ios::end);
              // _file_len = file.tellg();
              // file.seekg(std::ios::beg);
              // _is = is; Declaration of reference variable requires an
              // initializer
              // istream* _is = &is; It is reference, not address for pointer
          };

    auto begin() { return _data + _offset; }

    auto end() { return _data + _offset + _length; }

    auto discard(int n) {
        _offset += n;
        _length -= n;
    }

    // Returns the bytes number read
    auto extend() -> size_t {
        if (!_is.good()) {
            return 0;
        }
        if (BufferSize - _length > MinReadSize) {
            std::copy(begin(), end(), _data);
            _offset = 0;
        } else {
            // less than minimal read size to read
            return 0;
        }
        _is.read(_data, static_cast<long>(BufferSize) - _length);
        auto n = _is.gcount();
        _length += n;
        return n;
    }

  private:
    static constexpr size_t BufferSize = 16L * 1024;
    static constexpr size_t MinReadSize = BufferSize >> 2;  // 1/4
    // std::array<char, BufferSize> _data;
    char _data[BufferSize];
    std::istream& _is;
    std::streamsize _offset, _length;
};