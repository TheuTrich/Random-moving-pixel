import win32gui
import win32api
import random
import pyautogui

import os
import threading

width, height = pyautogui.size()

dc = win32gui.GetDC(0)

def randpxl(a, b):
    #lock.acquire()
    #lock.release()
    while (1):
        colors = win32api.RGB(random.randint(0, 255), random.randint(0, 255), random.randint(0, 255))
        win32gui.SetPixel(dc, a, b, colors)
        a = a + random.randint(-1, 1)
        b = b + random.randint(-1, 1)
        if a < 0:
            a = a + width
        if a > (width-1):
            a = a - width
        if b < 0:
            b = b + height
        if b > (height-1):
            b = b - height
    
if __name__ == "__main__":
    thread_lock = threading.Lock()

    t1 = threading.Thread(target=randpxl, args=(0, 0))
    
    t1.start()
    
    t1.join()
