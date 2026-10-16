
#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <exception>
#include <cstddef>

class Span {
public:
    Span();
    Span(unsigned int maxSize);
    Span(const Span &other);
    Span &operator=(const Span &other);
    ~Span();

    void addNumber(int value);

    template <typename InputIt>
    void addNumber(InputIt first, InputIt last) {
        std::size_t count = 0;
        for (InputIt it = first; it != last; ++it) {
            ++count;
        }
        if (_numbers.size() + count > static_cast<std::size_t>(_maxSize)) {
            throw SpanFullException();
        }
        _numbers.insert(_numbers.end(), first, last);
    }

    unsigned int shortestSpan() const;
    unsigned int longestSpan() const;

    class SpanFullException : public std::exception {
    public:
        virtual const char *what() const throw();
    };

    class SpanTooSmallException : public std::exception {
    public:
        virtual const char *what() const throw();
    };

private:
    unsigned int _maxSize;
    std::vector<int> _numbers;
};

#endif
