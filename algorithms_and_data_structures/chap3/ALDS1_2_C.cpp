#include <iostream>
#include <cstdlib>

int main()
{
    int N;
    std::cin >> N;
    int index_array_bubble_sort[N];
    char A_bubble_sort[N][2];
    int index_array_selection_sort[N];
    char A_selection_sort[N][2];
    char A[N][2];

    // 初期化
    for (int i = 0; i < N; i++)
    {
        std::cin >> A[i];
        A_selection_sort[i][0] = A[i][0];
        A_selection_sort[i][1] = A[i][1];
        A_bubble_sort[i][0] = A[i][0];
        A_bubble_sort[i][1] = A[i][1];

        index_array_selection_sort[i] = i;
        index_array_bubble_sort[i] = i;
    }

    // バブルソート
    for (int i = 0; i < N; i++)
    {
        for (int j = N - 1; i < j; j--)
        {
            if ((int)A_bubble_sort[index_array_bubble_sort[j - 1]][1] > (int)A_bubble_sort[index_array_bubble_sort[j]][1])
            {
                int tmp = index_array_bubble_sort[j - 1];
                index_array_bubble_sort[j - 1] = index_array_bubble_sort[j];
                index_array_bubble_sort[j] = tmp;
            }
        }
    }

    // 選択ソート
    for (int i = 0; i < N; i++)
    {
        int minj_index = i;
        int minj = 9;
        for (int j = i; j < N; j++)
        {
            if (strtol(&A_selection_sort[index_array_selection_sort[j]][1], NULL, 10) < minj)
            {
                minj_index = j;
                minj = strtol(&A_selection_sort[index_array_selection_sort[j]][1], NULL, 10);
            }
        }
        if (strtol(&A_selection_sort[index_array_selection_sort[i]][1], NULL, 10) != strtol(&A_selection_sort[index_array_selection_sort[minj_index]][1], NULL, 10))
        {
            int tmp = index_array_selection_sort[i];
            index_array_selection_sort[i] = index_array_selection_sort[minj_index];
            index_array_selection_sort[minj_index] = tmp;
        }
    }

    // 数字毎に登場順の表を作成
    char default_order_matrix[10][4] = {0};
    for (int i = 0; i < N; i++)
    {
        char card_type = A[i][0];
        int card_number = strtol(&A[i][1], NULL, 10);
        for (int j = 0; j < 4; j++)
        {
            if (!default_order_matrix[card_number - 1][j])
            {
                default_order_matrix[card_number - 1][j] = card_type;
                break;
            }
        }
    }

    // バブルソートでの数字毎に登場順の表を作成
    char bubble_sort_order_matrix[10][4] = {0};
    for (int i = 0; i < N; i++)
    {
        char card_type = A_bubble_sort[index_array_bubble_sort[i]][0];
        int card_number = strtol(&A_bubble_sort[index_array_bubble_sort[i]][1], NULL, 10);
        for (int j = 0; j < 4; j++)
        {
            if (!bubble_sort_order_matrix[card_number - 1][j])
            {
                bubble_sort_order_matrix[card_number - 1][j] = card_type;
                break;
            }
        }
    }

    // 選択ソートでの数字毎に登場順の表を作成
    char selection_sort_order_matrix[10][4] = {0};
    for (int i = 0; i < N; i++)
    {
        char card_type = A_selection_sort[index_array_selection_sort[i]][0];
        int card_number = strtol(&A_selection_sort[index_array_selection_sort[i]][1], NULL, 10);
        for (int j = 0; j < 4; j++)
        {
            if (!selection_sort_order_matrix[card_number - 1][j])
            {
                selection_sort_order_matrix[card_number - 1][j] = card_type;
                break;
            }
        }
    }

    bool is_bubble_sort_stable = true;
    bool is_selection_sort_stable = true;
    for (int i = 0; i < 10; i++)
    {
        char default_order_by_number[4] = {0};
        char bubble_sort_order_by_number[4] = {0};
        char selection_sort_order_by_number[4] = {0};
        for (int j = 0; j < 4; j++)
        {
            if (default_order_matrix[i][j] != bubble_sort_order_matrix[i][j])
            {
                is_bubble_sort_stable = false;
            }
            if (default_order_matrix[i][j] != selection_sort_order_matrix[i][j])
            {
                is_selection_sort_stable = false;
            }
        }
        for (int j = 0; j < 4; j++)
        {
        }
        for (int j = 0; j < 4; j++)
        {
        }
    }

    // 出力
    for (int i = 0; i < N; i++)
    {
        std::cout << A_bubble_sort[index_array_bubble_sort[i]][0] << A_bubble_sort[index_array_bubble_sort[i]][1];
        if (i == N - 1)
        {
            std::cout << std::endl;
        }
        else
        {
            std::cout << " ";
        }
    }
    if (is_bubble_sort_stable)
    {
        std::cout << "Stable" << std::endl;
    }
    else
    {
        std::cout << "Not stable" << std::endl;
    }

    for (int i = 0; i < N; i++)
    {
        std::cout << A_selection_sort[index_array_selection_sort[i]][0] << A_selection_sort[index_array_selection_sort[i]][1];
        if (i == N - 1)
        {
            std::cout << std::endl;
        }
        else
        {
            std::cout << " ";
        }
    }
    if (is_selection_sort_stable)
    {
        std::cout << "Stable" << std::endl;
    }
    else
    {
        std::cout << "Not stable" << std::endl;
    }
}