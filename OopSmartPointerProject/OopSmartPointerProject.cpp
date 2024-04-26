#include <iostream>
#include <utility>
#include "SmartPointer.h"

SmartPointer<Resource> generateResource(int value = 0)
{
    SmartPointer<Resource> result(new Resource(value));
    return result;
}

int ShareSmartPointer<Resource>::count = 0;

template <typename T>
void Swap(T& a, T& b)
{
    T temp{ std::move(a) };
    a = std::move(b);
    b = std::move(temp);
}

int main()
{

    /*SmartPointer<Resource> res1(new Resource(100));
    SmartPointer<Resource> res2(new Resource(200));*/

    std::unique_ptr<Resource> res1(new Resource(100));
    std::unique_ptr<Resource> res2(new Resource(200));
    
    std::unique_ptr<Resource> res3;
    res3 = std::move(res1);

    std::swap(res3, res2);
    std::cout << res3->Value() << " " << res2->Value() << "\n";

    
    std::shared_ptr<Resource> sh_res1(new Resource(500));
    std::shared_ptr<Resource> sh_res2(sh_res1);

    sh_res2->Value() = 1000;

    std::cout << sh_res1->Value() << "\n";

    /*ShareSmartPointer<Resource> resource1(new Resource(100));
    {
        ShareSmartPointer<Resource> resource2(resource1);
    }*/
    
    //SmartPointer<Resource> resource3 = generateResource();

    

    return 0;
}
