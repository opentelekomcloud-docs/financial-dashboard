Show Consumption (Hourly Granularity)
=====================================

.. rest_method:: GET /v2/hourly/consumption

This API streams your consumption data in batches of 1,000 records. The response is returned as a string, with each line representing a valid JSON object. You'll need to decode each line and parse it into JSON format on your end.

Please ensure you create an API Key either through the Financial Dashboard UI or via the Grafana API directly.

Note: API uses 'Europe/Berlin' as default timezone for parameters and response. If the same request is made with identical parameters within 1 hour, cached data will be returned instead of fresh data.

.. rest_status_code:: success ../http-status.yaml

   - 200

.. rest_status_code:: error ../http-status.yaml

   - 400
   - 422

Request
-------

.. rest_parameters:: ../parameters_v2.yaml

   - consumption_type: consumption_type
   - contract: contract
   - date: date
   - hour: hour
   - month: month
   - product: product
   - product_description: product_description
   - project_name: project_name
   - resource_id: resource_id
   - show_tag: show_tag
   - tag_key: tag_key
   - tag_value: tag_value
   - week: week
   - year: year

Curl Example
------------

Example request using curl with query parameters and headers:

.. literalinclude:: examples/consumption-hourly-get-curl
   :language: bash

Response Parameters
-------------------

Response Example (converted to JSON from byte string)
-----------------------------------------------------

.. literalinclude:: examples/consumption-get-hourly-response.json
   :language: javascript

Python Example
--------------

Example showing how to stream and parse the response in Python:

.. literalinclude:: examples/consumption-get-hourly.py
   :language: python


Show Consumption (Daily Granularity)
====================================

.. rest_method:: GET /v2/daily/consumption

This API streams your consumption data in batches of 1,000 records. The response is returned as a string, with each line representing a valid JSON object. You'll need to decode each line and parse it into JSON format on your end.

Please ensure you create an API Key either through the Financial Dashboard UI or via the Grafana API directly.

Note: API uses 'Europe/Berlin' as default timezone for parameters and response. If the same request is made with identical parameters within 1 hour, cached data will be returned instead of fresh data.

.. rest_status_code:: success ../http-status.yaml

   - 200

.. rest_status_code:: error ../http-status.yaml

   - 400
   - 422

Request
-------

.. rest_parameters:: ../parameters_v2.yaml

   - consumption_type: consumption_type
   - contract: contract
   - date: date
   - month: month
   - product: product
   - product_description: product_description
   - project_name: project_name
   - resource_id: resource_id
   - show_tag: show_tag
   - tag_key: tag_key
   - tag_value: tag_value
   - week: week
   - year: year

Curl Example
------------

Example request using curl with query parameters and headers:

.. literalinclude:: examples/consumption-daily-get-curl
   :language: bash

Response Parameters
-------------------

Response Example (converted to JSON from byte string)
-----------------------------------------------------

.. literalinclude:: examples/consumption-get-daily-response.json
   :language: javascript

Python Example
--------------

Example showing how to stream and parse the response in Python:

.. literalinclude:: examples/consumption-get-daily.py
   :language: python


Show Consumption (FOCUS 1.1)
============================

.. rest_method:: GET /v2/daily/consumption/focus

This API streams your consumption data aligned to the `FOCUS 1.1
<https://focus.finops.org/>`__ (FinOps Open Cost and Usage Specification)
column names at daily granularity. The same filters as the daily
consumption endpoint are supported, except ``hour``: FOCUS rows are daily
aggregates, so an ``hour`` filter is rejected with ``422`` instead of
silently returning an empty result.

The response is returned as a string (NDJSON), with each line
representing a valid JSON object. Data is streamed in batches of 1,000
records. You'll need to decode each line and parse it into JSON format
on your end.

Please ensure you create an API Key either through the Financial
Dashboard UI or via the Grafana API directly.

Note: API uses 'Europe/Berlin' as default timezone for parameters and
response. If the same request is made with identical parameters within
1 hour, cached data will be returned instead of fresh data.

Note: The ``show_tag``, ``tag_key`` and ``tag_value`` filters require the
``contract`` parameter to be set as well.

.. rest_status_code:: success ../http-status.yaml

   - 200

.. rest_status_code:: error ../http-status.yaml

   - 400
   - 422

Request
-------

.. rest_parameters:: ../parameters_v2.yaml

   - consumption_type: consumption_type
   - contract: contract
   - date: date
   - month: month
   - product: product
   - product_description: product_description
   - project_name: project_name
   - resource_id: resource_id
   - show_tag: show_tag
   - tag_key: tag_key
   - tag_value: tag_value
   - week: week
   - year: year

Curl Example
------------

Example request using curl with query parameters and headers:

.. literalinclude:: examples/consumption-focus-get-curl
   :language: bash

Response Parameters
-------------------

Each response line contains one charge with the following FOCUS 1.1
fields:

.. list-table::
   :widths: 25 12 63
   :header-rows: 1

   * - Field
     - Type
     - Description
   * - AvailabilityZone
     - string
     - Availability zone of the resource. Always ``null`` (not
       available).
   * - BilledCost
     - number
     - Billed cost of the charge in the billing currency (EUR).
   * - BillingAccountId
     - integer
     - Identifier of the billing (payer) account the contract belongs
       to.
   * - BillingAccountName
     - string
     - Name of the billing (payer) account the contract belongs to.
   * - BillingAccountType
     - string
     - Fixed value ``Billing Account``. Informational extension, not a
       FOCUS 1.1 column.
   * - BillingCurrency
     - string
     - Billing currency. Fixed value ``EUR``.
   * - BillingPeriodEnd
     - string
     - End of the billing period covered by the charge. Exclusive.
       Currently describes the daily period (consumption day + 1 day).
   * - BillingPeriodStart
     - string
     - Start of the billing period covered by the charge (the
       consumption day).
   * - CapacityReservationId
     - string
     - Resource identifier for reserved package (``RE``) charges;
       ``null`` otherwise.
   * - CapacityReservationStatus
     - string
     - Always ``null``.
   * - ChargeCategory
     - string
     - Charge category. Fixed value ``Usage``.
   * - ChargeClass
     - string
     - Always ``null``.
   * - ChargeDescription
     - string
     - Description of the consumed product or service.
   * - ChargeFrequency
     - string
     - Charge frequency. Fixed value ``Usage-Based``.
   * - ChargePeriodEnd
     - string
     - End of the charge period. Exclusive (consumption day + 1 day
       at daily granularity).
   * - ChargePeriodStart
     - string
     - Start of the charge period (the consumption day).
   * - CommitmentDiscountCategory
     - string
     - Always ``null`` (no commitment data available).
   * - CommitmentDiscountId
     - string
     - Always ``null``.
   * - CommitmentDiscountName
     - string
     - Always ``null``.
   * - CommitmentDiscountQuantity
     - number
     - Always ``null``.
   * - CommitmentDiscountStatus
     - string
     - Always ``null``.
   * - CommitmentDiscountType
     - string
     - Always ``null``.
   * - CommitmentDiscountUnit
     - string
     - Always ``null``.
   * - ConsumedQuantity
     - number
     - Consumed quantity of the charge.
   * - ConsumedUnit
     - string
     - Unit of ``ConsumedQuantity``, for example ``h`` or ``pc``.
   * - ContractedCost
     - number
     - Contracted cost in EUR. Currently equal to ``BilledCost``.
   * - ContractedUnitPrice
     - number
     - Always ``null``.
   * - EffectiveCost
     - number
     - Effective cost in EUR. Currently equal to ``BilledCost``.
   * - InvoiceId
     - string
     - Always ``null``.
   * - InvoiceIssuerName
     - string
     - Fixed value ``T-Systems International GmbH``.
   * - ListCost
     - number
     - Always ``null`` (no list price source available).
   * - ListUnitPrice
     - number
     - Always ``null``.
   * - PricingCategory
     - string
     - ``Committed`` for reserved packages (``RE``), ``Standard`` for
       elastic packages (``EL``), otherwise ``Other``.
   * - PricingCurrency
     - string
     - Pricing currency. Fixed value ``EUR``.
   * - PricingCurrencyContractedUnitPrice
     - number
     - Always ``null``. Informational extension, not a FOCUS 1.1
       column.
   * - PricingCurrencyEffectiveCost
     - number
     - Effective cost in the pricing currency (EUR). Currently equal
       to ``BilledCost``. Informational extension, not a FOCUS 1.1
       column.
   * - PricingCurrencyListUnitPrice
     - number
     - Always ``null``. Informational extension, not a FOCUS 1.1
       column.
   * - PricingQuantity
     - number
     - Priced quantity of the charge. Currently equal to
       ``ConsumedQuantity``.
   * - PricingUnit
     - string
     - Unit of ``PricingQuantity``. Currently equal to
       ``ConsumedUnit``.
   * - ProviderName
     - string
     - Fixed value ``T-Systems International GmbH``.
   * - PublisherName
     - string
     - Fixed value ``T-Systems International GmbH``.
   * - RegionId
     - string
     - Region where the service was consumed, for example ``EU-DE``.
   * - RegionName
     - string
     - Region name. Currently equal to ``RegionId``.
   * - ResourceId
     - string
     - Unique identifier of the resource. ``null`` when the charge is
       not resource based.
   * - ResourceName
     - string
     - Concatenation of ``ResourceId`` and ``ChargeDescription``
       (``"<resource_id> <product_description>"``). ``null`` when
       either part is missing.
   * - ResourceType
     - string
     - Product family of the resource. ``null`` when ``ResourceId``
       is ``null``.
   * - ServiceCategory
     - string
     - Category of the consumed service, for example ``Compute`` or
       ``Database``.
   * - ServiceName
     - string
     - Name of the consumed product or service. Currently equal to
       ``ChargeDescription``.
   * - ServiceSubcategory
     - string
     - Subcategory of the consumed service (product family).
   * - SubAccountId
     - integer
     - Identifier of the contract the charge belongs to.
   * - SubAccountName
     - string
     - Name of the contract the charge belongs to.
   * - SubAccountType
     - string
     - Fixed value ``contract``. Informational extension, not a
       FOCUS 1.1 column.
   * - Tags
     - object
     - All tags attached to the resource as a single JSON object.
       Only returned when ``show_tag=true`` is requested and the
       resource is tagged; ``null`` otherwise.

The FOCUS 1.1 columns ``SkuId``, ``SkuMeter``, ``SkuPriceId`` and
``SkuPriceDetails`` are not returned because no corresponding source
data is available.

Response Example (converted to JSON from byte string)
-----------------------------------------------------

.. literalinclude:: examples/consumption-get-focus-response.json
   :language: javascript

Python Example
--------------

Example showing how to stream and parse the response in Python:

.. literalinclude:: examples/consumption-get-focus.py
   :language: python
