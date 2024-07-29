#include "functions.h"

/*
Example of output :
╭──────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╮
│ Local Devices                                                                                                                                    │
├────────────────────────────────────────┬──────────┬──────────┬───────────┬────────────────────────────────┬──────────┬──────────┬────────────────┤
│ MOUNTED ON                             │ SIZE     │ USED     │ AVAILABLE │ USED%                          │ FREE     │ TYPE     │ FILESYSTEM     │
├────────────────────────────────────────┼──────────┼──────────┼───────────┼────────────────────────────────┼──────────┼──────────┼────────────────┤
│ /                                      │ 232.0 Go │  65.8 Go │ 154.3 Go  │ [######..............]  28.4 % │ 166.2 Go │ ext4     │ /dev/nvme0n1p5 │
│ /boot/efi                              │ 256.0 Mo │  35.2 Mo │ 220.8 Mo  │ [###.................]  13.7 % │ 220.8 Mo │ vfat     │ /dev/nvme0n1p1 │
╰────────────────────────────────────────┴──────────┴──────────┴───────────┴────────────────────────────────┴──────────┴──────────┴────────────────╯
╭──────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╮
│ Special Devices                                                                                                                                  │
├────────────────────────────────────────┬──────────┬──────────┬───────────┬────────────────────────────────┬──────────┬──────────┬────────────────┤
│ MOUNTED ON                             │ SIZE     │ USED     │ AVAILABLE │ USED%                          │ FREE     │ TYPE     │ FILESYSTEM     │
├────────────────────────────────────────┼──────────┼──────────┼───────────┼────────────────────────────────┼──────────┼──────────┼────────────────┤
│ /dev                                   │   9.6 Go │   0.0 o  │   9.6 Go  │ [....................]   0.0 % │   9.6 Go │ devtmpfs │ udev           │
│ /run                                   │   1.9 Go │   1.9 Mo │   1.9 Go  │ [....................]   0.1 % │   1.9 Go │ tmpfs    │ tmpfs          │
│ /dev/shm                               │   9.7 Go │   8.2 Mo │   9.7 Go  │ [....................]   0.1 % │   9.7 Go │ tmpfs    │ tmpfs          │
│ /run/lock                              │   5.0 Mo │  12.0 Ko │   5.0 Mo  │ [....................]   0.2 % │   5.0 Mo │ tmpfs    │ tmpfs          │
│ /snap/bare/5                           │ 128.0 Ko │ 128.0 Ko │   0.0 o   │ [####################] 100.0 % │   0.0 o  │ squashfs │ /dev/loop1     │
│ /snap/core20/2318                      │  64.0 Mo │  64.0 Mo │   0.0 o   │ [####################] 100.0 % │   0.0 o  │ squashfs │ /dev/loop0     │
│ /snap/notepad-plus-plus/405            │   7.5 Mo │   7.5 Mo │   0.0 o   │ [####################] 100.0 % │   0.0 o  │ squashfs │ /dev/loop4     │
│ /snap/gtk-common-themes/1535           │  91.8 Mo │  91.8 Mo │   0.0 o   │ [####################] 100.0 % │   0.0 o  │ squashfs │ /dev/loop3     │
│ /snap/gnome-3-38-2004/143              │ 349.8 Mo │ 349.8 Mo │   0.0 o   │ [####################] 100.0 % │   0.0 o  │ squashfs │ /dev/loop2     │
│ /snap/snapd/21759                      │  38.9 Mo │  38.9 Mo │   0.0 o   │ [####################] 100.0 % │   0.0 o  │ squashfs │ /dev/loop5     │
│ /snap/wine-platform-7-devel-core20/24  │ 453.1 Mo │ 453.1 Mo │   0.0 o   │ [####################] 100.0 % │   0.0 o  │ squashfs │ /dev/loop6     │
│ /snap/wine-platform-runtime-core20/126 │ 497.8 Mo │ 497.8 Mo │   0.0 o   │ [####################] 100.0 % │   0.0 o  │ squashfs │ /dev/loop8     │
│ /run/user/1000                         │   1.9 Go │ 152.0 Ko │   1.9 Go  │ [....................]   0.0 % │   1.9 Go │ tmpfs    │ tmpfs          │
│ /snap/wine-platform-runtime-core20/127 │ 495.2 Mo │ 495.2 Mo │   0.0 o   │ [####################] 100.0 % │   0.0 o  │ squashfs │ /dev/loop9     │
╰────────────────────────────────────────┴──────────┴──────────┴───────────┴────────────────────────────────┴──────────┴──────────┴────────────────╯

Difference between free and available :
  - Free : Free space (with reserved block)
  - Available : Real free space for non-root users)
*/

int main() {
    const char proc_mounts_path[] = "/proc/mounts";
    const char label_list_init[MAX_LIST][MAX_CONTENT] = {"MOUNTED ON", "SIZE", "USED", "AVAILABLE", "USED%", "FREE", "TYPE", "FILESYSTEM"};
    unsigned int len_file = LenFile(proc_mounts_path);

    char data[len_file][MAX_LENGTH_LINE];
    unsigned int size_max[MAX_LIST];

    const char special_types[9][10] = {"tmpfs", "devtmpfs", "proc", "sysfs", "cgroup", "overlay", "squashfs", "fuse", "#"};

    for (unsigned int i = 0; i < len_file; i++) {
        ReadLine(proc_mounts_path, data[i], i);
    }

    GetMaxLength(data, label_list_init, len_file, size_max);

    for (unsigned int i = 0; i < len_file; i++) {
        struct SysInfoSize info = GetSysInfo(data[i]);
        if (i == 0) {
            DisplayTitle(size_max, label_list_init, info, 1);
        }
        if (InfoIs_Present(info)) {
            if (!IsDevice(info.type, special_types)) {
                DisplayContent(info, size_max);
            }
        }
    }
    DisplayBot(size_max);

    for (unsigned int i = 0; i < len_file; i++) {
        ReadLine(proc_mounts_path, data[i], i);
    }

    GetMaxLength(data, label_list_init, len_file, size_max);

    for (unsigned int i = 0; i < len_file; i++) {
        struct SysInfoSize info = GetSysInfo(data[i]);
        if (i == 0) {
            DisplayTitle(size_max, label_list_init, info, 0);
        }
        if (InfoIs_Present(info)) {
            if (IsDevice(info.type, special_types)) {
                DisplayContent(info, size_max);
            }
        }
    }
    DisplayBot(size_max);
    printf("\n%sDifference between free and available :\n", ITALIC);
    printf("  - Free : Free space (with reserved block)\n");
    printf("  - Available : Real free space for non-root users)\n%s", NOCOLOR);
    return 0;
}
