public class Main {
    public static void main(String[] args) {
        ExpressionParser expressionParser = new ExpressionParser();
        ComplexExpression complexExpression = expressionParser.parse(args);
        if (complexExpression != null){
            ComplexNumber result = complexExpression.execute();
            System.out.println(result);
        }
    }
}