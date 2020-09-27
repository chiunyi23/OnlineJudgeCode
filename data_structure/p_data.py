#!/usr/bin/python # -*- coding: UTF-8 -*-

import random
with open('p_data.txt', 'w') as f:
    f.write('100000\n')
    for i in range(100000, 0, -1):
        a = random.randint(0, 100000)
        f.write(str(a) + ' ')