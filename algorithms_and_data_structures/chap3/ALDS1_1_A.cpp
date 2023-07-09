#include <iostream>

int main()
{
    int N;
    std::cin >> N;
    int A[N];

    // 入力の処理.
    for (int i = 0; i < N; i++)
    {
        std::cin >> A[i];
    }

    // 初回出力.
    for (int i = 0; i < N; i++)
    {
        std::cout << A[i];
        if (i != N - 1)
        {
            std::cout << " ";
        }
    }
    std::cout << std::endl;

    // ソート.
    for (int sorting_range = 1; sorting_range < N; sorting_range++)
    {
        int sort_target_number = A[sorting_range];
        int sort_target_number_index = sorting_range + 1;
        int sorted_max = sort_target_number;
        int sorted_max_index = sort_target_number_index;

        // std::cout << "現在ソート済みなのは" << sorting_range - 1 << "まで" << std::endl;
        // std::cout << "対象は" << sort_target_number << std::endl;

        // 挿入場所を特定する.
        // sort_target_number以下の最大値のインデックスを求める.
        for (int searching = 0; searching < sorting_range; searching++)
        {
            if (A[searching] > sorted_max && sort_target_number >= sorted_max)
            {
                sorted_max_index = searching;
                sorted_max = A[searching];
            }
        }

        // 入れ替えが必要な場合は入れ替えを行う.
        if (sorted_max_index != sort_target_number_index)
        {
            // std::cout << "挿入場所は" << sorted_max_index << "で" << A[sorted_max_index] << "の位置に入ります。" << std::endl;
            //  sorting range内の挿入場所以降のデータを1つずらす.
            for (int j = sorting_range; sorted_max_index < j; j--)
            {
                A[j] = A[j - 1];
            }
            // 挿入する.
            A[sorted_max_index] = sort_target_number;
        }
        else
        {
            // std::cout << "入れ替えは不要なのでスキップ" << std::endl;
        }

        // 都度出力.
        for (int k = 0; k < N; k++)
        {
            std::cout << A[k];
            if (k != N - 1)
            {
                std::cout << ' ';
            }
        }
        std::cout << std::endl;
    }
    return 0;
}