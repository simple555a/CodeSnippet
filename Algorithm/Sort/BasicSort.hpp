#ifndef __CYTL__BASICSORT__
#define __CYTL__BASICSORT__

#include "Comparable.hpp"
#include <iterator>

namespace CYTL
{
    template<class T>
    void swap(T& t1, T& t2)
    {
        T tmp(t1);
        t1 = t2;
        t2 = tmp;
    }

    // [begin, end)

    template<class Iterator, class Comparable = Less<typename std::iterator_traits<Iterator>::value_type> >
    void insertionSort(Iterator begin, Iterator end,
                       Comparable cmp = Less<typename std::iterator_traits<Iterator>::value_type>())
    {
        if(begin >= end) return;

        for(Iterator iter = begin+1; iter < end; iter++)
        {
            for(Iterator it = iter; it >= begin; it--)
            {
                if( cmp(*it, *(it-1)) ) swap(*it, *(it-1));
                else break;
            }
        }
    }


    template<class Iterator, class Comparable = Less<typename std::iterator_traits<Iterator>::value_type> >
    void selectionSort(Iterator begin, Iterator end,
                       Comparable cmp = Less<typename std::iterator_traits<Iterator>::value_type>())
    {
        if(begin >= end) return;

        for(Iterator iter = begin; iter < end; iter++)
        {
            Iterator smallestIter = iter;
            for(Iterator it = iter+1; it < end; it++)
            {
                if( cmp(*it, *smallestIter) )
                    smallestIter = it;
            }

            if(smallestIter != iter) swap(*smallestIter, *iter);
        }
    }

}

#endif // __CYTL__BASICSORT__