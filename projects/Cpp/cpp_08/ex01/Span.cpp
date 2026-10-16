
#include "Span.hpp"

#include <algorithm>

Span::Span() : _maxSize(0), _numbers() {}

Span::Span(unsigned int maxSize) : _maxSize(maxSize), _numbers() {}

Span::Span(const Span &other) : _maxSize(other._maxSize), _numbers(other._numbers) {}

Span &Span::operator=(const Span &other) {
    if (this != &other) {
        _maxSize = other._maxSize;
        _numbers = other._numbers;
    }
    return *this;
}

Span::~Span() {}

void Span::addNumber(int value) {
    if (_numbers.size() >= _maxSize) {
        throw SpanFullException();
    }
    _numbers.push_back(value);
}

unsigned int Span::shortestSpan() const {
    if (_numbers.size() < 2) {
        throw SpanTooSmallException();
    }

    std::vector<int> sorted(_numbers);
    std::sort(sorted.begin(), sorted.end());

    unsigned int minSpan = static_cast<unsigned int>(sorted[1] - sorted[0]);
    for (std::size_t i = 2; i < sorted.size(); ++i) {
        unsigned int span = static_cast<unsigned int>(sorted[i] - sorted[i - 1]);
        if (span < minSpan) {
            minSpan = span;
        }
    }
    return minSpan;
}

unsigned int Span::longestSpan() const {
    if (_numbers.size() < 2) {
        throw SpanTooSmallException();
    }

    std::vector<int>::const_iterator minIt = std::min_element(_numbers.begin(), _numbers.end());
    std::vector<int>::const_iterator maxIt = std::max_element(_numbers.begin(), _numbers.end());
    return static_cast<unsigned int>(*maxIt - *minIt);
}

const char *Span::SpanFullException::what() const throw() {
    return "span is full";
}

const char *Span::SpanTooSmallException::what() const throw() {
    return "not enough elements to compute span";
}
