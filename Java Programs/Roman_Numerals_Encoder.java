/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Programas_4Kyu;

/**
 *
 * @author Eros
 */

public class Roman_Numerals_Encoder {
    public String solution(int n) {
        String solucion="";
        String[] partido=Integer.toString(n).split("");
        int cont=0;
        for (int i = partido.length; i > 0; i--) {
            solucion=solucion+tranf(i, partido[cont]);
            cont++;
        }
        return solucion;
    }
    public String tranf(int i,String s){
        switch(i){
            case 4:
                switch(s){
                    case "3":return "MMM";
                    case "2":return "MM";
                    case "1":return "M";
                }
                break;
            case 3:
                switch(s){
                    case "0":return "";
                    case "9":return "CM";
                    case "8":return "DCCC";
                    case "7":return "DCC";
                    case "6":return "DC";
                    case "5":return "D";
                    case "4":return "CD";
                    case "3":return "CCC";
                    case "2":return "CC";
                    case "1":return "C";
                }
                break;
            case 2:
                switch(s){
                    case "0":return "";
                    case "9":return "XC";
                    case "8":return "LXXX";
                    case "7":return "LXX";
                    case "6":return "LX";
                    case "5":return "L";
                    case "4":return "XL";
                    case "3":return "XXX";
                    case "2":return "XX";
                    case "1":return "X";
                }
                break;
            case 1:
                switch(s){
                    case "0":return "";
                    case "9":return "IX";
                    case "8":return "VIII";
                    case "7":return "VII";
                    case "6":return "VI";
                    case "5":return "V";
                    case "4":return "IV";
                    case "3":return "III";
                    case "2":return "II";
                    case "1":return "I";
                }
                break;
        }
        
        return null;
    }
}
