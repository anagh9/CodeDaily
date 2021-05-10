import java.util.Scanner;

public class WorkingwithArray {
    public void arraymanipulation(){
        String s[];
        s =new String[4];
        String [] players = {"David", "Daniel", "Anna", "Gregory"};
        s[0] ="Anagh Kumar";
        s[1] ="Ramesh Kumar";
        s[2] ="Tarrak Mehta";
        s[3] ="Jethalal Gada";

        for(int i=0;i<4;i++){
            System.out.println("String Output : "+s[i]);
            System.out.println("Player Name : "+players[i]);
        }
    }
}

//  import java.util.Scanner;

//            WorkingwithArray wa =new WorkingwithArray();
//            wa.arraymanipulation();

//    Scanner sc = new Scanner(System.in);   // For Input

//        int [] arr;
//        arr =new int[5];

//        char [] arr;
//        arr = new char[5];


//        String [] arr;
//        arr =new String[5];

//         arr[i] = sc.next().charAt(0);  // Taking Char as Input
//         arr[i] =sc.next();    //Taking String as Input