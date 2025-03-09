#include "snake.h"

//// 主函数
//int main() {
//    // 测试用例
//    add_entry("data.txt", "Alice", 95);
//    add_entry("data.txt", "Bob Johnson", 82);
//    add_entry("data.txt", "Charlie", 107);
//    add_entry("data.txt", "David Copperfield", 65);
//
//    print_all("data.txt"); // 打印所有数据
//
//    printf("\n单行测试：\n");
//    print_line("data.txt", 2); // 打印第2行
//    print_line("data.txt", 5); // 错误行号测试
//
//    return 0;
//}

// 去除字符串右侧空格
void rtrim(char* str) {
    int n = strlen(str) - 1;
    while (n >= 0 && isspace(str[n])) n--;
    str[n + 1] = '\0';
}

// 比较函数（降序排序）
int compare_entries(const void* a, const void* b) {
    return ((Entry*)b)->number - ((Entry*)a)->number;
}

// 写入文件
void write_to_file(const char* filename, Entry* entries, int count) {
    FILE* file = fopen(filename, "w");
    if (!file) {
        perror("写入文件失败");
        return;
    }
    for (int i = 0; i < count; i++) {
        fprintf(file, "%-*s  %*d  %s\n",
            NAME_WIDTH, entries[i].name,
            NUMBER_WIDTH, entries[i].number,
            entries[i].time);
    }
    fclose(file);
}

// 获取当前时间
void get_current_time(char* time_str) {
    time_t now = time(NULL);
    struct tm* t = localtime(&now);
    snprintf(time_str, TIME_WIDTH + 1, "%04d-%02d-%02d %02d:%02d",
        t->tm_year + 1900, t->tm_mon + 1, t->tm_mday,
        t->tm_hour, t->tm_min);
}

// 读取文件内容
int read_entries_from_file(const char* filename, Entry* entries) {
    FILE* file = fopen(filename, "r");
    if (!file) return 0; // 文件不存在时返回0

    int count = 0;
    char line[256];

    while (fgets(line, sizeof(line), file) && count < MAX_ENTRIES) {
        // 解析固定宽度格式
        strncpy(entries[count].name, line, NAME_WIDTH);
        entries[count].name[NAME_WIDTH] = '\0';
        rtrim(entries[count].name);

        sscanf(line + NAME_WIDTH + 2, "%d", &entries[count].number);

        strncpy(entries[count].time, line + NAME_WIDTH + 2 + NUMBER_WIDTH + 2, TIME_WIDTH);
        entries[count].time[TIME_WIDTH] = '\0';
        rtrim(entries[count].time);

        count++;
    }
    fclose(file);
    return count;
}

// 添加条目
void add_entry(const char* filename, const char* name, int number) {
    if (strlen(name) > NAME_WIDTH) {
        printf("错误：姓名长度超过%d字符\n", NAME_WIDTH);
        return;
    }

    Entry entries[MAX_ENTRIES];
    int count = read_entries_from_file(filename, entries);

    if (count < MAX_ENTRIES) {
        Entry* e = &entries[count];
        strncpy(e->name, name, NAME_WIDTH);
        e->number = number;
        get_current_time(e->time);
        count++;
    }

    qsort(entries, count, sizeof(Entry), compare_entries);
    write_to_file(filename, entries, count);
}

// 打印指定行
void print_line(const char* filename, int line_number) {
    Entry entries[MAX_ENTRIES];
    int total = read_entries_from_file(filename, entries);

    if (line_number < 1 || line_number > total) {
        printf("错误：行号 %d 无效（共%d行）\n", line_number, total);
        return;
    }

    Entry* e = &entries[line_number - 1];
    printf("%-*s  %*d  %s\n",
        NAME_WIDTH, e->name,
        NUMBER_WIDTH, e->number,
        e->time);
}

// 打印所有条目
void print_all(const char* filename) {
    Entry entries[MAX_ENTRIES];
    int count = read_entries_from_file(filename, entries);

    printf("\n%-*s  %*s  %s\n",
        NAME_WIDTH, "姓名",
        NUMBER_WIDTH, "分数",
        "时间");

    // 生成分隔线
    for (int i = 0; i < NAME_WIDTH + NUMBER_WIDTH + TIME_WIDTH + 4; i++)
        putchar('-');
    putchar('\n');

    for (int i = 0; i < count; i++) {
        printf("%-*s  %*d  %s\n",
            NAME_WIDTH, entries[i].name,
            NUMBER_WIDTH, entries[i].number,
            entries[i].time);
    }
}