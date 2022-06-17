#include <iostream>
#include <Collections/LinkedList.h>
#include <Maths/Rect.h>


int main()
{
    std::cout << "Hello World!\n";

    LinkedList<int> ints;
    ints.PushBack(5);
    ints.PushBack(21);

    for (int i : ints)
    {
        std::cout << i << std::endl;
    }

    Rect rect = { 0, 0, 100, 200 };
    std::cout << rect.Area() << std::endl;

    return 0;
}
