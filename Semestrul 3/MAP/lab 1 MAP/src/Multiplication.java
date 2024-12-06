class Multiplication extends ComplexExpression {
    public Multiplication(ComplexNumber[] args) {
        super(args);
        this.operation = Operation.MULTIPLICATION;
    }

    @Override
    public ComplexNumber executeOneOperation(ComplexNumber res, ComplexNumber c) {
        return res.multiply(c);
    }
}
