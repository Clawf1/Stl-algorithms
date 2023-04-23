#ifndef LABWORK_11_CLAWF1_ALGORITHMS_H
#define LABWORK_11_CLAWF1_ALGORITHMS_H

#endif //LABWORK_11_CLAWF1_ALGORITHMS_H

#include <iostream>

template<class InputIt, class Predicate>
constexpr bool all_of(InputIt first, InputIt last, Predicate p) {
    for(; first != last; ++first) {
        if (!p(*first)) return false;
    }
    return true;
}

template<class InputIt, class Predicate>
bool any_of(InputIt first, InputIt last, Predicate p) {
    for (; first != last; ++first) {
        if (p(*first)) return true;
    }
    return false;
}

template<class InputIt, class Predicate>
bool none_of(InputIt first, InputIt last, Predicate p) {
    return !any_of(first, last, p);
}

template<class InputIt, class Predicate>
bool one_of(InputIt first, InputIt last, Predicate p) {
    int count = 0;
    for (; first != last; ++first) {
        if (p(*first)) ++count;
        if (count > 1) return false;
    }
    return count == 1;
}

template<class ForwardIt, class Compare>
bool is_sorted(ForwardIt first, ForwardIt last, Compare comp) {
    if (first != last) {
        ForwardIt next = first;
        while(++next != last) {
            if (!comp(*first, *next))
                return false;
            first = next;
        }
    }
    return true;
}

template<class InputIt, class Predicate>
bool is_partitioned(InputIt first, InputIt last, Predicate p) {
    if (first == last) return true;
    bool t = p(*first);
    for (; first != last; ++first) {
        if (p(*first) != t) break;
    }
    t = !t;
    for (; first != last; ++first) {
        if (p(*first) != t) return false;
    }
    return true;
}
template<class InputIt, typename T>
InputIt find_not(InputIt first, InputIt last, const T& value) {
    for(; first != last; ++first)
        if (*first != value) return first;
    return last;
}

template<class ForwardIt, typename T>
ForwardIt find_backward(ForwardIt first, ForwardIt last, const T& val) {
    ForwardIt ans = last;
    for (; first != last; ++first) {
        if (*first == val) ans = first;
    }
    return ans;
}

template<class BidirectionalIt>
bool is_palindrome(BidirectionalIt first, BidirectionalIt last) {
    --last;
    for (;;) {
        if (*first != *last) return false;
        if (++first == last) break;
        if (first == --last) break;
    }
    return true;
}

template<typename T, typename U>
class CXrange {
private:
    T first_;
    T last_;
    U step_;
public:
    CXrange(T first, T last, U step) : first_(first), last_(last), step_(step){};
    class xIterator {
    public:
        typedef std::input_iterator_tag iterator_category;
        typedef T value_type;
        typedef T* pointer;
        typedef T& reference;
        typedef ptrdiff_t difference_type;
    private:
        T value;
        U step;
    public:
        xIterator(T val, U st) : value(val), step(st){};

        T operator*() {
            return value;
        }
        bool operator!=(const xIterator& rhs) {
            return (value < rhs.value && step > 0) || (value > rhs.value && step < 0);
        }
        bool operator==(const xIterator& rhs) {
            return (value >= rhs.value && step >= 0) || (value <= rhs.value && step <= 0);
        }
        xIterator& operator++() {
            value += step;
            return *this;
        }
        xIterator operator++(int) {
            xIterator temp = *this;
            value += step;
            return temp;
        }
    };

    xIterator begin() {
        return xIterator(first_, step_);
    }
    xIterator end() {
        return xIterator(last_, step_);
    }

};

template<typename T>
CXrange<T, int> xrange(const T& last) {
    return CXrange<T, int>(T(), last, 1);
}

template<typename T>
CXrange<T, int> xrange(const T& first, const T& last) {
    return CXrange<T, int>(first, last, 1);
}

template<typename T, typename U>
CXrange<T, U> xrange(const T& first, const T& last, const U& step) {
    return CXrange<T, U>(first, last, step);
}


template<class First, class Second>
class CZip {
private:
    typename First::const_iterator begin1;
    typename First::const_iterator end1;
    typename Second::const_iterator begin2;
    typename Second::const_iterator end2;
public:
    CZip(const First& f, const Second& s) : begin1(f.begin()), end1(f.end()), begin2(s.begin()), end2(s.end()) {};
    class ZipIterator {
    private:
        typename First::const_iterator f;
        typename Second::const_iterator s;
    public:
        ZipIterator(typename First::const_iterator beg1, typename Second::const_iterator beg2) : f(beg1), s(beg2) {};
        std::pair<typename First::value_type, typename Second::value_type> operator*() {
            return std::make_pair(*f, *s);
        }
        ZipIterator& operator++() {
            f++;
            s++;
            return *this;
        }
        ZipIterator operator++(int) {
            ZipIterator temp = *this;
            f++;
            s++;
            return temp;
        }
        bool operator==(ZipIterator &rhs) {
            if (f == rhs.f || s == rhs.s) return false;
            return true;
        }
        bool operator!=(ZipIterator &rhs) {
            if (f != rhs.f && s != rhs.s) return true;
            return false;
        }
    };
    ZipIterator begin() {
        return ZipIterator(begin1, begin2);
    }
    ZipIterator end() {
        return ZipIterator(end1, end2);
    }
};

template<class F, class S>
CZip<F, S> zip(const F& first, const S& second) {
    return CZip(first, second);
}