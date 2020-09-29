#include <algorithm>
#include <iterator>



// Distance
// ========

template <typename T>
struct Distance {
    T operator () (const T& a, const T&  b) {
        return std::abs(a - b);
    }
};

// Compare Distance
// ================

template <
    typename T,
    typename DistanceFunctor = Distance<T>,
    typename CompareFunctor = std::less<decltype(
        std::declval<DistanceFunctor>()(std::declval<T>(), std::declval<T>()))>>
struct CompareDistance
{
    T pivot;
    DistanceFunctor distance;
    CompareFunctor compare;
    CompareDistance(T&& pivot)
    :   pivot(std::move(pivot))
    {}

    CompareDistance(T&& pivot, DistanceFunctor&& distance)
    :   pivot(std::move(pivot)),
        distance(std::move(distance))
    {}

    CompareDistance(T&& pivot, DistanceFunctor&& distance, CompareFunctor&& compare)
    :   pivot(std::move(pivot)),
        distance(std::move(distance)),
        compare(std::move(compare))
    {}

    bool operator () (const T& a, const T& b) {
        return compare(distance(a, pivot), distance(b,  pivot));
    }
};

// Distance Sort
// =============

template <typename Iterator, typename T>
inline void distance_sort(
    Iterator first,
    Iterator last,
    T&& pivot)
{
    typedef typename std::iterator_traits<Iterator>::value_type value_type;
    CompareDistance<value_type> compare_distance(std::move(pivot));
    std::sort(first, last, compare_distance);
}

template <typename Iterator, typename T, typename Distance>
inline void distance_sort(
    Iterator first,
    Iterator last,
    T&& pivot,
    Distance&& distance)
{
    typedef typename std::iterator_traits<Iterator>::value_type value_type;
    CompareDistance<value_type, Distance> compare_distance(
        std::move(pivot),
        std::move(distance));
    std::sort(first, last, compare_distance);
}

template <typename Iterator, typename T, typename Distance, typename Compare>
inline void distance_sort(
    Iterator first,
    Iterator last,
    T&& pivot,
    Distance&& distance,
    Compare&& compare)
{
    typedef typename std::iterator_traits<Iterator>::value_type value_type;
    CompareDistance<value_type, Distance, Compare> compare_distance(
        std::move(pivot),
        std::move(distance),
        std::move(compare));
    std::sort(first, last, compare_distance);
}

// Test
// ====

#include <iostream>

int main() {
    std::vector<int> original = { 56, 10, 79841651, 45, 59, 68, -20, 0, 36, 23, -3256 };

    // Find closest neighbours [less]:
    std::vector<int> elements(original);
    distance_sort(begin(elements), end(elements), 4);

    for(const auto& e : elements)
        std::cout << e << ' ';
    std::cout << '\n';

    // Find closest neighbours [greater]:
    distance_sort(begin(elements), end(elements), 4, Distance<int>(), std::greater<int>());

    for(const auto& e : elements)
        std::cout << e << ' ';
    std::cout << '\n';

    // Without distance_sort, but with existing tools
    std::sort(
        begin(elements),
        end(elements),
        [](int a, int b) {
            const int pivot = 4;
            return std::abs(a - pivot) < std::abs(b - pivot);
        }
    );

    for(const auto& e : elements)
        std::cout << e << ' ';
    std::cout << '\n';
}
