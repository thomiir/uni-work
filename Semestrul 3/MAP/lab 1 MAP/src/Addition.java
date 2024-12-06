class Addition extends ComplexExpression {

    public Addition(ComplexNumber[] args) {
        super(args);
        this.operation = Operation.ADDITION;
    }

    @Override
    public ComplexNumber executeOneOperation(ComplexNumber res, ComplexNumber c) {
        return res.add(c);
    }
}
