#include <iostream>
#include <algorithm>
#include <vector>

// алгоритм должен работать с forward итераторами
// и возвращать итератор, который потом будет передан
// в метод erase соответствующего контейнера
template<class FwdIt>
FwdIt remove_nth(FwdIt p, FwdIt q, size_t n)
{
	size_t i = 0;

	FwdIt it = std::remove_if(p, q, [&i, &n](...){
    	bool res = false;

    	if (i == n) {
    		res = true;
    	}

    	i += 1;
    	return res;
    });

    return it;
}
