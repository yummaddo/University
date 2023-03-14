#include <iostream>
#include <chrono>

class Timer {
private:
    int m_hour;
    int m_minute;
    int m_second;
    std::chrono::time_point<std::chrono::high_resolution_clock> m_startTime;
    int* m_data = nullptr;
    int m_dataSize = 0;


public:
    Timer(int hour, int minute, int second)
        : m_hour(hour), m_minute(minute), m_second(second),
          m_startTime(std::chrono::high_resolution_clock::now())
    {
        std::cout << "Timer created with time: " << m_hour << "hours : " << m_minute << "minutes : " << m_second << "seconds " << std::endl;
    }

    ~Timer()
    {
        // очищення пам'яті
        std::cout << "Clear var:: m_data with values :: ";
        for (int i = 0; i < m_dataSize; i++) {
            std::cout << "Index: " << i << " Value: " << m_data[i] << std::endl;
        }

        delete[] m_data;
        m_data = nullptr;
        m_dataSize = 0;
        
        std::chrono::duration<double> elapsed = std::chrono::high_resolution_clock::now() - m_startTime;
        std::cout << "Timer destroyed. Time elapsed: " << elapsed.count() << " seconds." << std::endl;
    }

    // метод для заповнення масиву даними
    void fillData(int size)
    {
        m_data = new int[size];
        m_dataSize = size;
        for (int i = 0; i < size; i++) {
            m_data[i] = i;
        }
    }


};

int main()
{
    Timer t(1, 2, 3);
    t.fillData(1000000);
    // ...
    return 0;
} // тут буде викликаний деструктор