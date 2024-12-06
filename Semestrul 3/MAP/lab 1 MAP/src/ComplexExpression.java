public abstract class ComplexExpression {
    protected Operation operation;
    protected ComplexNumber[] args;

    public ComplexExpression(ComplexNumber[] args){
        this.args = args;
    }

    public final ComplexNumber execute(){
        ComplexNumber res = args[0];
        for (int i = 1; i < args.length; i++)
            res = executeOneOperation(res, args[i]);
        return res;
    }

    public abstract ComplexNumber executeOneOperation(ComplexNumber res, ComplexNumber c);
}

