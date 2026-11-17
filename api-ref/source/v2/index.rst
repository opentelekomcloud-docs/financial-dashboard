:tocdepth: 3

=====================================
Financial Dashboard API v2 (Current)
=====================================

As an admin user of your organization, you can create API keys, these API keys will allow you to gather consumption data
for your organization.

**Be aware that API keys from a global organization (payer account) can access data of all tenants, which are part of
the global organization.**

You can create API Keys in your organization settings (**Configuration** > **API Keys**) or via API. The tokens are valid for up
to 90 days per default. Please make sure that the token security level is set as “Admin” during creation.

API keys are created in the Financial Dashboard web UI at
https://financial-dashboard.otc-service.com. Sign in to the Grafana-based web UI with an Admin user and open
**Configuration** (gear icon) > **API Keys**. See the `Financial Dashboard User Manual
<https://docs.otc.t-systems.com/enterprise-dashboard/umn/>`__ for access and user management.

You can access https://api-enterprise-dashboard.otc-service.com/ to get started with different API endpoints as well.
Please keep in mind that you still need at least a user account with admin permissions to interact with the API. All
endpoints, except the Health and Version Endpoints, require Authentication.

Important: Now "v2" api streams data and don't use pagination, so response is "ndjson" in bytes format and not json. It is done for efficient
bulk data response.

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

