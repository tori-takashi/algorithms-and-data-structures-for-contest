#include <iostream>

int main()
{
    int N;
    std::cin >> N;
    int A[N];
    for (int i = 0; i < N; i++)
    {
        std::cin >> A[i];
    }

    int sorted_index = 0;
    int sort_times = 0;
    for (int sorting = N - 1; 0 < sorting; sorting--)
    {
        int sort_target_number = A[sorting];
        std::cout << "ソート対象のA[" << sorting << "] = " << A[sorting] << std::endl;

        for (int sort_target_number_index = sorting; sorted_index < sort_target_number_index; sort_target_number_index--)
        {
            int sort_target_back_number_index = sort_target_number_index - 1;
            int sort_target_back_number = A[sort_target_back_number_index];
            // 直前の要素のほうが大きい時に入れ替える.
            if (sort_target_number < sort_target_back_number)
            {
                std::cout << "ソート対象の数" << sort_target_number << "が直前の要素" << sort_target_back_number << "より大きいので入れ替え" << std::endl;
                A[sort_target_back_number_index] = sort_target_number;
                A[sort_target_number_index] = sort_target_back_number;
                sort_times++;
            }
            else
            {
                std::cout << "ソート対象の数" << sort_target_number << "が直前の要素" << sort_target_back_number << "より小さいので打ち切り" << std::endl;
                break;
            }
        }

        for (int i = 0; i < N; i++)
        {
            std::cout << A[i] << " ";
        }
        std::cout << std::endl;
    }

    // 出力.
    for (int i = 0; i < N; i++)
    {
        std::cout << A[i];
        if (i != N - 1)
        {
            std::cout << " ";
        }
    }
    std::cout << std::endl
              << sort_times << std::endl;
}