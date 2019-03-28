HKU-Engg1340-Group6
-------------------

![](https://img.shields.io/github/release/lidantong/HKU-Engg1340-Group6.svg)
![](http://progressed.io/bar/15?title=completed)
![](https://img.shields.io/badge/language-C%2B%2B-green.svg)


> Good management consists in showing average people how to do the work of superior people.                                   
> John D. Rockefeller

Problem Statement:flashlight:
-----------------

This C++ project is aiming at helping **grocery stores** and the like to manage the waiting list of customers.

**In reality**, cashiers in grocery stores are usually crowded with people carrying various types and amounts of groceries. We assume that:
- The store holds **no cashier** at first and each new one will cost a certain amount of money.
- Each customer carries different items waiting to checkout with equal "patience" -- he or she is willing to wait for a certain amount of time, or will just leave without any purchase.
- Groceries have different prices and the total number of items determines the time of a single checkout procedure.
- The store has the right to adjust the order of the waiting line.

The goal of our project is to provide **optimised plans** of queuing to obtain a maximum profit of a given grocery store as well as generate grocery stores with specific or random parameters.

Feature Support:gift:
---------------

The project is capable of the following features: (to be continued...)

1. To read from grocery file including information such as goods and their prices.(default: data validation)
2. To randomly generate a customer with certain grocery goods.(for test)
3. To get one piece of customers' information from manual input. (default: data validation)
4. To generate a queue where customers are in a certain order. (one cannot cut line)
5. To calculate the processing time of each customer at the cashiers.
6. To get a maximum number of cashiers from standard input. (fewer than the default number: 50)
7. To get a command from the standard input about whether to set an express line for customers with goods fewer than a certain number(another input).
8. To optimise the number of cashiers for maximum profit and display the detailed distribution strategy.

Authors:eyes:
----------

* **Ruichen Ma** <<alexmrc@hku.hk>>
* **Dantong Li** <<ldtzyj@hku.hk>>
