public class ExpressionFactory {
    private static final ExpressionFactory expressionFactory = new ExpressionFactory();

    private ExpressionFactory(){}

    public static ExpressionFactory getInstance(){
        return expressionFactory;
    }

    public ComplexExpression createExpression(Operation operation, ComplexNumber[] args){
        return switch (operation){
            case ADDITION -> new Addition(args);
            case SUBTRACTION -> new Subtraction(args);
            case MULTIPLICATION -> new Multiplication(args);
            case DIVISION -> new Division(args);
        };
    }
}
