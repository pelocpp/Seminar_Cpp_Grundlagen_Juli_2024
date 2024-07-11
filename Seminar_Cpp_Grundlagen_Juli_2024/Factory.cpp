// ===========================================================================
// ConceptualExample.cpp // Factory a.k.a. Simple Factory
// ===========================================================================

#include <iostream>
#include <string>
#include <memory>

namespace ConceptualExample {

    // Schnittstelle
    class IShape
    {
    public:
        virtual ~IShape() {}

        virtual void draw() = 0;
    };

    // Realisierung einer Klasse samt Schnittstelle
    class Rectangle : public IShape
    {
    public:
        Rectangle() {}

        void draw() override
        {
            std::cout << "> Rectangle::draw()" << std::endl;
        }
    };

    class TestRectangle : public IShape
    {
    public:
        TestRectangle() {}

        void draw() override
        {
            std::cout << "> TestRectangle::draw()" << std::endl;
        }

        // add ons
        void dump()
        {
            // write dump to console
        }

    };

    // 1. Variante // nicht sehr gut
    //Rectangle needRectangle()  // "Möchte ein Rectangle haben"
    //{
    //    Rectangle emtpy;
    //    return emtpy;
    //}

    // 2.  Variante: Wesentlich besser
    IShape* needShape(int what)  // "Möchte ein Rectangle haben"
    {
        if (what == 1)
        {
            // 1 soll für Rechteck stehen

        // WRONG !!!!!!!
        //Rectangle emtpy;
        //return &emtpy;

        // kann nicht über den Stack gehen (empty liegt am Stack)

        // der Heap / Halde ist es
        //Rectangle* ptr = new Rectangle();
        //return ptr;  // passt, weil Rectangle hat IShape als Vaterklasse

        // ODER
            IShape* ptr = new Rectangle();
            return ptr;  // passt, weil Rectangle hat IShape als Vaterklasse
        }
        else
        {
            return nullptr;
        }
    }

    IShape* needRectangle()  // "Möchte ein Rectangle haben"
    {
        // IShape* ptr = new Rectangle();
        IShape* ptr = new TestRectangle();

        return ptr;  // passt, weil Rectangle hat IShape als Vaterklasse
    }


    // Client
    void test()
    {
        IShape* rect  = needShape(1);  // 1 symbolisiert eine Kennung:
                                       // gib mir ein Rechteck

        // weiß von der Klasse 'Rectangle' nichts
        IShape* anotherRect = needRectangle();

        // anotherRect->
    }




    // ==================================================================
    // ==================================================================
    // ==================================================================


    class Square : public IShape
    {
    public:
        Square() {}

        void draw() override
        {
            std::cout << "> Square::draw()" << std::endl;
        }
    };

    class Circle : public IShape
    {
    public:
        Circle() {}

        void draw() override
        {
            std::cout << "> Circle ::draw()" << std::endl;
        }
    };

    class ShapeFactory
    {
        enum class StringCode
        {
            Rectangle,
            Square,
            Circle,
            None
        };

    public:

        // IShape* getShape(std::string shapeType)

        std::shared_ptr<IShape> getShape(std::string shapeType)  // IShape*
        {
            enum class StringCode shape = stringToEnum(shapeType);

            switch (shape)
            {
            case StringCode::Rectangle:
                return std::make_shared<ConceptualExample::Rectangle>();
            case StringCode::Square:
                return std::make_shared<ConceptualExample::Square>();
            case StringCode::Circle:
                return std::make_shared<ConceptualExample::Circle>();
            default:
                std::string msg = "Invalid type: " + shapeType;
                throw std::runtime_error{ msg };
            }
        }

    private:
        StringCode stringToEnum(const std::string& s) {

            if (s == "Rectangle") {
                return StringCode::Rectangle;
            }
            else if (s == "Square") {
                return StringCode::Square;
            }
            else if (s == "Circle") {
                return StringCode::Circle;
            }
            else {
                return StringCode::None;
            }
        }
    };

    static void test_without_factory()
    {
        // using classes explicitely
        //
        Rectangle* rect{ new Rectangle{} };
        rect->draw();

        Circle* circle{ new Circle{} };
        circle->draw();

        Square* square{ new Square{} };
        square->draw();
    }

    static void test_with_factory()
    {
        // using classes indirectly with factory
        // (knowledge about explicit classes not necessary)
        // 
        ShapeFactory shapeFactory;

        std::shared_ptr<IShape> shape{};

        shape = shapeFactory.getShape("Circle");
        shape->draw();

        shape = shapeFactory.getShape("Rectangle");
        shape->draw();

        shape = shapeFactory.getShape("Square");
        shape->draw();
    }
}

void test_conceptual_example()
{
    using namespace ConceptualExample;
    test_without_factory();
    test_with_factory();
}

// ===========================================================================
// End-of-File
// ===========================================================================