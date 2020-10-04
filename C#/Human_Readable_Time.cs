using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

class Human_Readable_Time
{
    public static string GetReadableTime(int seconds)
    {
        return "" +
            ((((int)seconds / 3600) < 10 ? "0" + ((int)seconds / 3600) : "" + ((int)seconds / 3600)) + ":" +
            (((int)(seconds % 3600) / 60) < 10 ? "0" + ((int)(seconds % 3600) / 60) : "" + ((int)(seconds % 3600) / 60)) + ":" +
            (((int)seconds % 3600 % 60) < 10 ? "0" + ((int)seconds % 3600 % 60) : "" + ((int)seconds % 3600 % 60)));
    }
}
