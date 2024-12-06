import java.util.List;
import java.util.Objects;
import java.util.regex.Matcher;
import java.util.regex.Pattern;
import java.util.ArrayList;

public class ExpressionParser {
    private static final String COMPLEX_NUMBER_REGEX = "-?\\d+";

    public ComplexExpression parse(String[] args) {
        Operation operation = getOperation(args[1]);
        List<ComplexNumber> complexNumbers = parseComplexNumbers(args);
        return createExpression(operation, complexNumbers);
    }

    private Operation getOperation(String operator) {
        return switch (operator) {
            case "+" -> Operation.ADDITION;
            case "-" -> Operation.SUBTRACTION;
            case "*" -> Operation.MULTIPLICATION;
            case "/" -> Operation.DIVISION;
            default -> throw new IllegalArgumentException("Invalid operator");
        };
    }

    private List<ComplexNumber> parseComplexNumbers(String[] args) {
        List<ComplexNumber> complexNumbers = new ArrayList<>();
        Pattern pattern = Pattern.compile(COMPLEX_NUMBER_REGEX);
        for (int i = 0; i < args.length; i += 2) {
            Matcher matcher = pattern.matcher(args[i]);
            String realPart = "0";
            String imaginaryPart = "0";
            if (matcher.find()) {
                realPart = matcher.group(0);
                if (matcher.find())
                    imaginaryPart = matcher.group(0);
            }
            complexNumbers.add(new ComplexNumber(Float.parseFloat(realPart), Float.parseFloat(imaginaryPart)));
        }
        return complexNumbers;
    }

    private ComplexExpression createExpression(Operation operation, List<ComplexNumber> complexNumbers) {
        ComplexNumber[] numbersArray = complexNumbers.toArray(new ComplexNumber[0]);
        return ExpressionFactory.getInstance().createExpression(operation, numbersArray);
    }
}
