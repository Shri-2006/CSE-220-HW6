shri@shri-Aspire-A14-52MT:~/CSE-220-HW6$ echo "hello this is shri testing"  > tests.in/mytest.txt



Command 'valgrind' not found, but can be installed with:
sudo snap install valgrind  # version 3.26.0, or
sudo apt  install valgrind  # version 1:3.22.0-0ubuntu2
See 'snap info valgrind' for additional versions.
shri@shri-Aspire-A14-52MT:~/CSE-220-HW6$ sudo apt install valgrind
[sudo] password for shri:     
Reading package lists... Done
Building dependency tree... Done
Reading state information... Done
The following packages were automatically installed and are no longer required:
  linux-headers-6.8.0-100 linux-headers-6.8.0-100-generic linux-headers-6.8.0-101 linux-headers-6.8.0-101-generic linux-headers-6.8.0-106
  linux-headers-6.8.0-106-generic
Use 'sudo apt autoremove' to remove them.
Suggested packages:
  valgrind-dbg valgrind-mpi kcachegrind alleyoop valkyrie
The following NEW packages will be installed:
  valgrind
0 upgraded, 1 newly installed, 0 to remove and 0 not upgraded.
Need to get 14.9 MB of archives.
After this operation, 78.8 MB of additional disk space will be used.
Get:1 http://archive.ubuntu.com/ubuntu noble/main amd64 valgrind amd64 1:3.22.0-0ubuntu3 [14.9 MB]
Fetched 14.9 MB in 2s (6,589 kB/s)   
Selecting previously unselected package valgrind.
(Reading database ... 665633 files and directories currently installed.)
Preparing to unpack .../valgrind_1%3a3.22.0-0ubuntu3_amd64.deb ...
Unpacking valgrind (1:3.22.0-0ubuntu3) ...
Setting up valgrind (1:3.22.0-0ubuntu3) ...
Processing triggers for man-db (2.12.0-4build2) ...
N: Ignoring file 'nosnap.backup' in directory '/etc/apt/preferences.d/' as it has an invalid filename extension
shri@shri-Aspire-A14-52MT:~/CSE-220-HW6$ valgrind --leak-check=full ./bin/hw6 -s the -r end -l 1,1 tests.in/mytest.txt tests.out/mytest.txt
==89996== Memcheck, a memory error detector
==89996== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.
==89996== Using Valgrind-3.22.0 and LibVEX; rerun with -h for copyright info
==89996== Command: ./bin/hw6 -s the -r end -l 1,1 tests.in/mytest.txt tests.out/mytest.txt
==89996== 
==89996== 
==89996== HEAP SUMMARY:
==89996==     in use at exit: 944 bytes in 2 blocks
==89996==   total heap usage: 4 allocs, 2 frees, 9,136 bytes allocated
==89996== 
==89996== LEAK SUMMARY:
==89996==    definitely lost: 0 bytes in 0 blocks
==89996==    indirectly lost: 0 bytes in 0 blocks
==89996==      possibly lost: 0 bytes in 0 blocks
==89996==    still reachable: 944 bytes in 2 blocks
==89996==         suppressed: 0 bytes in 0 blocks
==89996== Reachable blocks (those to which a pointer was found) are not shown.
==89996== To see them, rerun with: --leak-check=full --show-leak-kinds=all
==89996== 
==89996== For lists of detected and suppressed errors, rerun with: -s
==89996== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
shri@shri-Aspire-A14-52MT:~/CSE-220-HW6$ 