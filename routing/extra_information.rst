.. index::
   single: Routing; Extra Information

How to Pass Extra Information from a Route to a Controller
==========================================================

Parameters inside the ``defaults`` collection don't necessarily have to match
a placeholder in the route ``path``. In fact, you can use the ``defaults``
array to specify extra parameters that will then be accessible as arguments
to your controller, and as attributes of the ``Request`` object:

.. configuration-block::

    .. code-block:: yaml

        # app/config/routing.yml
        blog:
            path:      /blog/{page}
            defaults:
                _controller: AppBundle:Blog:index
                page:        1
                title:       "Hello world!"

    .. code-block:: xml

        <!-- app/config/routing.xml -->
        <?xml version="1.0" encoding="UTF-8" ?>
        <routes xmlns="http://symfony.com/schema/routing"
            xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
            xsi:schemaLocation="http://symfony.com/schema/routing
                http://symfony.com/schema/routing/routing-1.0.xsd">

            <route id="blog" path="/blog/{page}">
                <default key="_controller">AppBundle:Blog:index</default>
                <default key="page">1</default>
                <default key="title">Hello world!</default>
            </route>
        </routes>

    .. code-block:: php

        // app/config/routing.php
        use Symfony\Component\Routing\RouteCollection;
        use Symfony\Component\Routing\Route;

        $routes = new RouteCollection();
        $routes->add('blog', new Route('/blog/{page}', array(
            '_controller' => 'AppBundle:Blog:index',
            'page'        => 1,
            'title'       => 'Hello world!',
        )));

        return $routes;

Now, you can access this extra parameter in your controller, as an argument
to the controller method::

    public function indexAction($page, $title)
    {
        // ...
    }

Alternatively, the title could be accessed through the ``Request`` object::

    use Symfony\Component\HttpFoundation\Request;

    public function indexAction(Request $request, $page)
    {
        $title = $request->attributes->get('title');

        // ...
    }

As you can see, the ``$title`` variable was never defined inside the route
path, but you can still access its value from inside your controller, through
the method's argument, or from the ``Request`` object's ``attributes`` bag.
