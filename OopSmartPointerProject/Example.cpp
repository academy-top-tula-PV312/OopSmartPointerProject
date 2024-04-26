#include "SmartPointer.h"

void func()
{
    //Resource* resource = new Resource();
    SmartPointer<Resource> resPtr(new Resource());

    //resource->Value() = 200;

    resPtr->Value() = 100;
    std::cout << resPtr->Value() << "\n";
}

void funcCopy(SmartPointer<Resource> resource2)
{

}

void PrintValue(int& value)
{
    std::cout << "l-value " << value << "\n";
}

void PrintValue(int&& value)
{
    std::cout << "r-value " << value << "\n";
}


int Return100()
{
    int result = 100;
    return result;
}

void Example1()
{
    //func();
    //funcCopy(resource1);

    /*int&& number = 10;

    std::cout << &number << "\n";*/

    //int r = Return100();


    //int& number_ref = number;

    //int&& rv_ref{ 10 };

    /*auto&& rv_resource{ Resource(10) };
    rv_resource.Value() = 100;

    rv_resource = Resource(200);*/

    int x{ 123 };
    PrintValue(x);
    PrintValue(123);
}