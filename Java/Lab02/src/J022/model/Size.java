package J022.model;

public class Size {
    private double m2_area;

    public Size(double m2_area) {
        this.m2_area = m2_area;
    }

    public double getPyungArea() {
        return m2_area / 3.305;
    }

    public String getSizeCategory() {
        double pyung = getPyungArea();
        if (pyung < 15) return "small";
        else if (pyung < 30) return "normal";
        else if (pyung < 50) return "large";
        else return "huge";
    }
}