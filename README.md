HKU-Engg1340-Group6
-------------------

![](http://progressed.io/bar/100?title=completed)
![](https://img.shields.io/github/release/lidantong/HKU-Engg1340-Group6.svg)
![](https://img.shields.io/badge/Language-C%2B%2B11-green.svg)



> Good management consists of showing average people how to do the work of superior people.
>
> John D. Rockefeller

Problem Statement :flashlight:
-----------------

This C++ project is aiming at helping **grocery stores** and the like to manage the waiting list of customers.

Talking about daily life, the management of cashiers is crucial to the **total revenue** and customers' experience. When customers have formed a long line, the number of cashiers counts greatly for the total revenue. With too few cashiers, customers may get **impatient** and give up their purchase, while too many cashiers can cause **unneccesary waste** of human resource. Thus, it can be unbelievably helpful for a grocery store to have a programme that can produce the **best number of cashiers** and the **corresponding revenue**.

Problem Setting :arrows_counterclockwise:
---

We have made a few **assumptions** to immitate the real life: 
1. Customers only differ from each other about the items to be purchased. (e.g. same maximum waiting time)
2. Customers stand in a **single FIFO** waiting line. (i.e. first in first out)
3. Each item of the same kind has a **fixed amount of time** for checking out.
4. The program can collect information about groceries, customers and the expense of opening a new cashier in a given format.
5. User input is valid for most of the cases. (Including pre-set files if needed)

Installation :black_square_button:
---

- Clone this repo to your local folder
  ```bash
  git clone https://github.com/lidantong/HKU-Engg1340-Group6.git
  ```
- Enter the git directory and build your programme
  ```bash
  make grocery_store
  ```
- Execute the programme
  ```bash
  ./grocery_store
  ```
Satisfaction guaranteed!

Feature Support :gift:
---------------

The project is capable of the following **features**:
1. The programme can print a lovely logo and manual pages.
2. The programme can tolerate **most of the wrong input**.
3. The **input unit** is a customer. User can both manually input the information of a customer or indicate an exsiting file to do so.
4. It can randomly generate customers in an arbitary scale which depends on the machine. (For test)
5. The programme can adapt to variable environment including the maximun poossible number of cashiers, customer's maximum wating time and the expenditure of opending a new cashier.
6. Finally it can produce the best number of cashiers and the corresponding revenue.
7. It can delete all the information files with a suffix ".txt".
8. Designed user-guiding flow.

IO Specification
---

- Names should contain one word. (e.g. dragon_fruit)
- Time variables may only contain integers.
- Command should be all-capital letters.
- Filename indicates a file existing in the current working directory or should be an absolute location.
- When asked whether to delete the info files, users' confirmation requires input twice.

Sample IO
---
- Test1: Manual input
- Test2: File input
- Test3: File input + Adaption to the environment
- Test4: Test

```bash
./grocary_store < Input?.txt # '?' is in {1, 2, 3, 4}
```

[Detailes in here](Testcases/)

Authors:eyes:
----------

* **Ruichen Ma** <<alexmrc@hku.hk>>
* **Dantong Li** <<ldtzyj@hku.hk>>
