placeholder
~~~~~~~~~~~

.. versionadded:: 2.6
    The ``placeholder`` option was introduced in Symfony 2.6 and replaces
    ``empty_value``, which is available prior to 2.6.

.. versionadded:: 2.3
    Since Symfony 2.3, empty values are also supported if the ``expanded``
    option is set to true.

**type**: ``string`` or ``boolean``

This option determines whether or not a special "empty" option (e.g. "Choose
an option") will appear at the top of a select widget. This option only
applies if the ``multiple`` option is set to false.

* Add an empty value with "Choose an option" as the text::

    $builder->add('states', 'choice', array(
        'placeholder' => 'Choose an option',
    ));

* Guarantee that no "empty" value option is displayed::

    $builder->add('states', 'choice', array(
        'placeholder' => false,
    ));

If you leave the ``placeholder`` option unset, then a blank (with no text)
option will automatically be added if and only if the ``required`` option
is false::

    // a blank (with no text) option will be added
    $builder->add('states', 'choice', array(
        'required' => false,
    ));
