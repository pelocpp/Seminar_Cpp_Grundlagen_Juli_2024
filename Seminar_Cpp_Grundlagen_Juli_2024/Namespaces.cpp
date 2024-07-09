
namespace TestWithMockData
{
    void test_mit_test_daten()
    {
        // mock daten
    }

    namespace TestWithSpecialMockData
    {
        void test_mit_special_test_daten()
        {
            // database daten
        }
    }
}

namespace TestWithDatabaseData {

    void test_mit_test_daten()
    {
        // database daten
    }
}

void test()
{
    using namespace TestWithDatabaseData;

    TestWithDatabaseData::test_mit_test_daten();

    TestWithMockData::TestWithSpecialMockData::test_mit_special_test_daten();
}


