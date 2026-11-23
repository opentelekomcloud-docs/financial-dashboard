:tocdepth: 3

=====================================
Financial Dashboard API v2 (Current)
=====================================

As an admin user of your organization, you can create API keys or service account tokens; these allow you to gather
consumption data for your organization.

**Be aware that credentials from a global organization (payer account) can access data of all tenants, which are part
of the global organization.**

Grafana recommends service account tokens instead of API keys. Both are created in the Financial Dashboard web UI at
https://financial-dashboard.otc-service.com (or via the Grafana API). Sign in with an Admin user and open
**Configuration** (the gear icon):

- **Service accounts** (recommended): click **New service account**, give it a display name, assign it the **Admin**
  role, then open the service account and click **Add token**. Copy the generated token; it inherits the permissions of
  the service account. Set an expiry date as required.
- **API Keys**: click **New API key**, set the security level to “Admin” and choose a validity period. API keys are
  valid for up to 90 days per default.

See the `Financial Dashboard User Manual
<https://docs.otc.t-systems.com/enterprise-dashboard/umn/>`__ for access and user management.

You can access https://api-enterprise-dashboard.otc-service.com/ to get started with different API endpoints as well.
Please keep in mind that you still need at least a user account with admin permissions to interact with the API. All
endpoints, except the Health and Version Endpoints, require Authentication.

Important: The "v2" API streams data without pagination for efficient bulk
data response. The daily and hourly consumption endpoints return NDJSON. The
daily FOCUS endpoint also supports JSON and CSV responses through the
``format`` query parameter.

.. image:: /images/image3.png
   :width: 6.62222in
   :height: 3.07153in

-----------
Consumption
-----------
.. include:: consumption.inc

------
Health
------
.. include:: health.inc

--------
Versions
--------
.. include:: versions.inc

