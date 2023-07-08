#include <iostream>

const int types_of_card = 4;
const int card_max_number = 13;

const char spade = 'S';
const int spade_column = 0;
const char heart = 'H';
const int heart_column = 1;
const char clover = 'C';
const int clover_column = 2;
const char diamond = 'D';
const int diamond_column = 3;

int get_column_by_card_type(char card_type)
{
    switch (card_type)
    {
    case spade:
        return spade_column;
    case heart:
        return heart_column;
    case clover:
        return clover_column;
    case diamond:
        return diamond_column;
    }
    return 0;
}

char get_type_of_card_by_column(int column)
{
    switch (column)
    {
    case spade_column:
        return spade;
    case heart_column:
        return heart;
    case clover_column:
        return clover;
    case diamond_column:
        return diamond;
    }
    return 0;
}

int get_row_by_card_number(int card_number)
{
    return card_number - 1;
}

bool card_is_contained()
{
    return true;
}

bool card_is_not_contained()
{
    return false;
}

bool is_card_not_contained(bool card_cell)
{
    return !card_cell;
}

int main()
{
    int total_card_count;
    bool card_matrix[card_max_number][types_of_card];

    // 入力長を取得.
    std::cin >> total_card_count;

    // 初期化.
    for (int column = 0; column < types_of_card; column++)
    {
        for (int row = 0; row < card_max_number; row++)
        {
            card_matrix[row][column] = card_is_not_contained();
        }
    }

    // 手持ちのカード情報を入力.
    for (int current_card_count = 0; current_card_count < total_card_count; current_card_count++)
    {
        char card_type;
        int card_number;
        std::cin >> card_type >> card_number;
        card_matrix[get_row_by_card_number(card_number)][get_column_by_card_type(card_type)] = card_is_contained();
    }

    // 出力.
    for (int card_type_column = 0; card_type_column < types_of_card; card_type_column++)
    {
        for (int card_number = 1; card_number <= card_max_number; card_number++)
        {
            if (is_card_not_contained(card_matrix[get_row_by_card_number(card_number)][card_type_column]))
                std::cout << get_type_of_card_by_column(card_type_column) << ' ' << card_number << std::endl;
        }
    }

    return 0;
}