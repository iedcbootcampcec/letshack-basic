/*
 *The new "Avengers" movie has just been released! There are a lot of people at the cinema box office standing in a huge line. Each of them has a single 100, 50 or 25 dollar bill. An "Avengers" ticket costs 25 dollars.
 *Vasya is currently working as a clerk. He wants to sell a ticket to every single person in this line.
 *Can Vasya sell a ticket to every person and give change if he initially has no money and sells the tickets strictly in the order people queue?
 *Return YES, if Vasya can sell a ticket to every person and give change with the bills he has at hand at that moment. Otherwise return NO.
 */


using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CodeWars.kiu6
{
    public static class VasyaClerk
    {
        public static string Tickets(int[] peopleInLine)
        {
            int _25 = 0;
            int _50 = 0;
            int _100 = 0;
            string possible = "YES";

            foreach (int people in peopleInLine)
            {
                switch (people)
                {
                    case (25):
                        _25 += 1;
                        break;
                    case (50):
                        if(_25 > 0)
                        {
                            _25 -= 1;
                            _50 += 1;
                        } else { possible = "NO"; }
                        break;
                    case (100):
                        if(_50 > 0 && _25 > 0)
                        {
                            _50 -= 1;
                            _25 -= 1;
                            _100 += 1;
                        } else if(_25 > 2)
                        {
                            _25 -= 3;
                            _100 += 1;
                        } else { possible = "NO"; }
                        break;
                }
            }
            return possible;
        }
    }
}
