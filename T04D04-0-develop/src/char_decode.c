#include <stdio.h>

int to_dec(char* hex) {
    long long decimal = 0, base = 1;
    int i = 0, length = 0;
    for (int i = 0; hex[i]; ++i) {
        ++length;
    }
    for (i = length--; i >= 0; i--) {
        if (hex[i] >= '0' && hex[i] <= '9') {
            decimal += (hex[i] - 48) * base;
            base *= 16;
        } else if (hex[i] >= 'A' && hex[i] <= 'F') {
            decimal += (hex[i] - 55) * base;
            base *= 16;
        } else if (hex[i] >= 'a' && hex[i] <= 'f') {
            decimal += (hex[i] - 87) * base;
            base *= 16;
        }
    }
    // printf("%lld", decimal);
    return decimal;
}

int decode() {
    char buf[256];

    char tmp[256];

    int size = 0;

    char* temp = NULL;
    char* str = NULL;

    temp = fgets(buf, 256, stdin);  // more safe

    if (temp) {
        str = temp;
    } else {
        printf("n/a");
        return 0;
    }

    for (int i = 0; str[i]; ++i) {
        if ((str[i] - '0' >= 0 && str[i] - '0' <= 9) || (str[i] >= 65 && str[i] <= 70)) {
            tmp[size++] = str[i];
        } else if (str[i] == ' ') {
            tmp[size] = '\0';
            size = 0;
            printf("%C", to_dec(tmp));
            printf("%c", ' ');
        } else if (str[i] == '\n') {
            tmp[size] = '\0';
            to_dec(tmp);
            printf("%C", to_dec(tmp));
            break;
        } else {
            printf("n/a");
            return 0;
        }
    }

    return 0;
}

int encode() {
    char buf[256];
    int size = 0;
    char temp;
    char next;
    while (1) {
        temp = getchar();
        if (temp == '\n') {
            printf("n/a");
            return 0;
        }
        next = getchar();
        if (next != ' ') {
            if (next != '\n') {
                printf("n/a");
                return 0;
            } else {
                buf[size++] = temp;
                break;
            }
        }

        buf[size++] = temp;
    }

    for (int j = 0; j != size - 1; ++j) {
        printf("%X ", (int)buf[j]);
    }

    printf("%X", (int)buf[size - 1]);

    return 0;
}

int main(int argc, char* argv[]) {

	//printf("%s%s%s", argv[0], argv[1], argv[2]);

	if (!argc) {
		printf("n/a");
	}

    if (*argv[1]) {
        if (*argv[1] - '0' == 0) {
            encode();
        } else if (*argv[1] - '0' == 1) {
            decode();
        } else {
            printf("n/a");
        }
    } else {
        printf("n/a");
    }
}