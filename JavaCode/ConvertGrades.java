public class ConvertGrades {

    public char convertGrades(int testResult) {
        char grade;
        if(testResult>= 90){
            grade =  'A';
        }

        else if(testResult>=80 && testResult<90){
            grade = 'B';
        }
        else if(testResult>60 && testResult<=80 ){
            grade ='C';
        }
        else if(testResult>40 && testResult<=60){
            grade = 'D';
        }
        else{
            grade ='F';
        }

        return grade;
    }
}

//        ConvertGrades cr =new ConvertGrades();
//        System.out.println( "Your Grade is : "+cr.convertGrades(60));
//        System.out.println( "Your Grade is : "+cr.convertGrades(90));
//        System.out.println( "Your Grade is : "+cr.convertGrades(20));
//        System.out.println( "Your Grade is : "+cr.convertGrades(75));
//        System.out.println( "Your Grade is : "+cr.convertGrades(38));