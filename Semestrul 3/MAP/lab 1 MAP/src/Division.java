class Division extends ComplexExpression {
    public Division(ComplexNumber[] args) {
        super(args);
        this.operation = Operation.DIVISION;
    }

    @Override
    public ComplexNumber executeOneOperation(ComplexNumber res, ComplexNumber c) {
        return res.divide(c);
    }
}
