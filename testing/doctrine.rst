.. index::
   single: Tests; Doctrine

How to Test Doctrine Repositories
=================================

Unit testing Doctrine repositories in a Symfony project is not recommended.
When you're dealing with a repository, you're really dealing with something
that's meant to be tested against a real database connection.

Fortunately, you can easily test your queries against a real database, as
described below.

Functional Testing
------------------

If you need to actually execute a query, you will need to boot the kernel
to get a valid connection. In this case, you'll extend the ``KernelTestCase``,
which makes all of this quite easy::

    // src/AppBundle/Tests/Repository/ProductRepositoryFunctionalTest.php
    namespace AppBundle\Tests\Repository;

    use AppBundle\Entity\Product;
    use Symfony\Bundle\FrameworkBundle\Test\KernelTestCase;

    class ProductRepositoryFunctionalTest extends KernelTestCase
    {
        /**
         * @var \Doctrine\ORM\EntityManager
         */
        private $entityManager;

        /**
         * {@inheritDoc}
         */
        protected function setUp()
        {
            self::bootKernel();
            $this->entityManager = static::$kernel->getContainer()
                ->get('doctrine')
                ->getManager()
            ;
        }

        public function testSearchByCategoryName()
        {
            $products = $this->entityManager
                ->getRepository(Product::class)
                ->searchByCategoryName('foo')
            ;

            $this->assertCount(1, $products);
        }

        /**
         * {@inheritDoc}
         */
        protected function tearDown()
        {
            parent::tearDown();

            $this->entityManager->close();
            $this->entityManager = null; // avoid memory leaks
        }
    }
