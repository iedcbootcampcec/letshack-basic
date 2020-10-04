/*
 *The Pied Piper has been enlisted to play his magical tune and coax all the rats out of town.
 *But some of the rats are deaf and are going the wrong way!
 *
 *P = The Pied Piper
 *O~ = Rat going left
 *~O = Rat going right
 */
 
 using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CodeWars.kiu6
{
    public static class DeafRatsOfHamelin
    {
        public static int CountDeafRats(string town)
        {
            string solution = town.Replace(" ", "");
            string left = solution.Substring(0, solution.IndexOf("P"));
            string right = solution.Substring(solution.IndexOf("P")+1);
            int count = 0;

            // Deaf rats at left side of piper
            for (int i=0; i<left.Length; i+=2)
            {
                if (left[i + 1].Equals('~')) count++;
            }

            // Deaf rats at right side of piper
            for(int i=0; i<right.Length; i += 2)
            {
                if (right[i].Equals('~')) count++;
            }

            return count;
        }

        public static int Better(string town)
        {
            var rats = town.Replace(" ", "").Split('P');
            var leftCount = rats[0].Where((x, i) => i % 2 == 1).Count(x => x == '~');
            var rightCount = rats[1].Where((x, i) => i % 2 == 0).Count(x => x == '~');
            return leftCount + rightCount;
        }
    }
}
