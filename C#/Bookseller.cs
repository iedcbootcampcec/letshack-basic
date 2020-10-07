/*
Help the bookseller! (Kiu 6 codewars code)

A bookseller has lots of books classified in 26 categories labeled A, B, ... Z. Each book has a code c of 3, 4, 5 or more characters. The 1st character of a code is a capital letter which defines the book category.
In the bookseller's stocklist each code c is followed by a space and by a positive integer n (int n >= 0) which indicates the quantity of books of this code in stock.
*/

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CodeWars.kiu6
{
    public static class Bookseller
    {
        public static string stockSummary(string[] lstOfArt, string[] lstOf1stLetter)
        {
            StringBuilder result = new StringBuilder();
            
            if(lstOfArt.Length == 0 || lstOf1stLetter.Length == 0)
            {
                result.Append("");
            } else
            {
                foreach (string key in lstOf1stLetter)
                {
                    result.Append("(" + key + " : ");
                    int sum = 0;

                    foreach (string book in lstOfArt)
                    {
                        if (string.Equals(key, book.Substring(0, 1)))
                        {
                            sum += Int32.Parse(book.Substring(book.IndexOf(" ")));
                        }
                    }
                    result.Append(sum + ") - ");
                }
                if (result.Length > 1) result.Remove(result.Length - 3, 3);
            }
            
            return result.ToString();
        }
    }
}
