class Subtraction extends ComplexExpression {
    public Subtraction(ComplexNumber[] args) {
        super(args);
        this.operation = Operation.SUBTRACTION;
    }

    @Override
    public ComplexNumber executeOneOperation(ComplexNumber res, ComplexNumber c) {
        return res.subtract(c);
    }
}
