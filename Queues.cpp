#include <iostream>
using namespace std;

class Queues
{
    private:
        static const int MAX = 5;
        int FRONT, REAR;
        int queues_array[5];

    public:
        Queues()
        {
            FRONT = -1;
            REAR = -1;
        }

    };